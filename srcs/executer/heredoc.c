/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:02:25 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:02:25 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// same to the one exists in expansion.c
static char	*replace_variable(char *before, int start, char *key)
{
	char	*after;
	char	*last;
	char	*head;
	char	*tail;
	char	*env_value;

	before[start] = '\0';
	head = before;
	last = before + start + 1 + ft_strlen(key);
	env_value = get_env(key);
	tail = ft_xstrjoin(env_value, last);
	after = ft_xstrjoin(head, tail);
	free(env_value);
	free(tail);
	free(before);
	return (after);
}

char	*expand_env(char *line)
{
	char	*key;
	size_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$')
		{
			key = get_env_key(line + i);
			if (key != NULL)
			{
				line = replace_variable(line, i, key);
				free(key);
				continue ;
			}
		}
		i++;
	}
	return (line);
}

bool	is_quoted(const char *str)
{
	char	*s;

	s = ft_strchr(str, '"');
	if (s != NULL && s != ft_strrchr(str, '"'))
		return (true);
	s = ft_strchr(str, '\'');
	if (s != NULL && s != ft_strrchr(str, '\''))
		return (true);
	return (false);
}

char	*extract_quote(char *str)
{
	char	*extracted_str;
	char	*current_str;

	extracted_str = (char *)ft_xcalloc(ft_strlen(str) + 1, sizeof(char));
	current_str = extracted_str;
	while (*str != '\0')
	{
		if (*str == '"')
			while (*(++str) != '"' && *str != '\0')
				*current_str++ = *str;
		else if (*str == '\'')
			while (*(++str) != '\'' && *str != '\0')
				*current_str++ = *str;
		else
			*current_str++ = *str++;
	}
	*current_str = *str;
	return (extracted_str);
}

int	heredoc_read(t_exec_info *info)
{
	int		pipe_fd[2];
	char	*line;

	xpipe(pipe_fd);
	while (1)
	{
		set_signal_heredoc();
		line = readline("> ");
		if (line == NULL
			|| ft_strcmp(line, extract_quote(info->heredoc_word)) == 0)
		{
			free(line);
			break ;
		}
		if (!is_quoted(info->heredoc_word))
			line = expand_env(line);
		ft_putendl_fd(line, pipe_fd[WRITE_INDEX]);
		free(line);
	}
	xclose(pipe_fd[WRITE_INDEX]);
	return (pipe_fd[READ_INDEX]);
}
