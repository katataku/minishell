/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:43:48 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/15 11:43:48 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

char	*super_join(char *first, char *second, char *third)
{
	char	*str;

	str = ft_xstrjoin(first, ft_xstrjoin(second, third));
	free(first);
	return (str);
}

char	*expand(char *word)
{
	char	*key;
	size_t	i;
	int		mode;

	i = 0;
	mode = NEUTRAL;
	while (word[i] != '\0')
	{
		if (word[i] == '"' && mode != IN_SQUOTE)
		{
			if (mode == IN_DQUOTE)
				mode = NEUTRAL;
			else
				mode = IN_DQUOTE;
			ft_memmove(word + i, word + i + 1, ft_strlen(word + i));
			continue ;
		}
		if (word[i] == '\'' && mode != IN_DQUOTE)
		{
			if (mode == IN_SQUOTE)
				mode = NEUTRAL;
			else
				mode = IN_SQUOTE;
			ft_memmove(word + i, word + i + 1, ft_strlen(word + i));
			continue ;
		}
		if (word[i] == '$' && mode != IN_SQUOTE)
		{
			key = get_env_key(word + i);
			if (key != NULL)
			{
				word[i] = '\0';
				word = super_join(word, get_env(key), \
					word + i + 1 + ft_strlen(key));
				free(key);
				continue ;
			}
		}
		i++;
	}
	return (word);
}

void	expand_cmd(t_exec_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->cmd_num)
	{
		j = 0;
		while (info->cmds[i][j] != NULL)
		{
			info->cmds[i][j] = expand(info->cmds[i][j]);
			j++;
		}
		i++;
	}
}
