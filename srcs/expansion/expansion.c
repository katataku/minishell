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

char	*get_env_key(char *word)
{
	size_t	i;

	if (word[0] != '$')
		return (NULL);
	if (!ft_isalpha(word[1]) && word[1] != '_')
		return (NULL);
	i = 2;
	while (ft_isalnum(word[i]) || word[i] == '_')
	{
		i++;
	}
	return (ft_substr(word, 1, i - 1));
}

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
		if (word[i] == '"')
		{
			mode = IN_DQUOTE;
			(void)mode;
			ft_memmove(word + i, word + i + 1, ft_strlen(word + i));
		}
		if (word[i] == '\'')
		{
			mode = IN_SQUOTE;
			ft_memmove(word + i, word + i + 1, ft_strlen(word + i));
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
