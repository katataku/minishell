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

static char	*replace_variable(char *before, int start, char *key)
{
	char	*after;
	char	*last;

	before[start] = '\0';
	last = before + start + 1 + ft_strlen(key);
	after = ft_xstrjoin(before, ft_xstrjoin(get_env(key), last));
	free(key);
	free(before);
	return (after);
}

static void	shift_left(char *word)
{
	ft_memmove(word, word + 1, ft_strlen(word));
}

static bool	handle_quotes(int *mode, char *word)
{
	bool	is_shifted;

	is_shifted = false;
	if (*word == '"' && *mode != IN_SQUOTE)
	{
		if (*mode == IN_DQUOTE)
			*mode = NEUTRAL;
		else
			*mode = IN_DQUOTE;
		shift_left(word);
		is_shifted = true;
	}
	else if (*word == '\'' && *mode != IN_DQUOTE)
	{
		if (*mode == IN_SQUOTE)
			*mode = NEUTRAL;
		else
			*mode = IN_SQUOTE;
		shift_left(word);
		is_shifted = true;
	}
	return (is_shifted);
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
		if (ft_strchr("\"'", word[i]) && handle_quotes(&mode, word + i))
			continue ;
		if (word[i] == '$' && mode != IN_SQUOTE)
		{
			key = get_env_key(word + i);
			if (key != NULL)
			{
				word = replace_variable(word, i, key);
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
