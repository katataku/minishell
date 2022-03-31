#include "executer.h"

static bool	is_envname(char c)
{
	return (ft_isalpha(c) || c == '_');
}

static char	*str_append(char *src, char dst)
{
	char	*appended_str;
	size_t	len;

	len = ft_strlen(src);
	appended_str = (char *)ft_xcalloc(len + 2, sizeof(char));
	ft_strlcpy(appended_str, src, len + 1);
	appended_str[len] = dst;
	free(src);
	return (appended_str);
}

char	*expand_env(char *line)
{
	char	*key;
	char	*expanded;

	expanded = ft_xstrdup("");
	while (*line != '\0')
	{
		if (*line == '$')
		{
			line++;
			key = ft_xstrdup("");
			while (is_envname(*line))
			{
				key = str_append(key, *(line++));
			}
			expanded = ft_xstrjoin(expanded, get_env(key));
		}
		else
			expanded = str_append(expanded, *(line++));
	}
	return (expanded);
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

/*
 * ^Cは表示されてしまう
 * heredoc実行中は、改行表示後にexitすることでmainループに戻る
 */
void	sigint_handler_heredoc(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', 1);
	exit(1);
	return ;
}

/*
 * SIGQUITは特に何もしなくても無視されていそう
 */
void	set_signal_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sigint_handler_heredoc);
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
		if (is_quoted(info->heredoc_word))
			ft_putendl_fd(line, pipe_fd[WRITE_INDEX]);
		else
			ft_putendl_fd(expand_env(line), pipe_fd[WRITE_INDEX]);
		free(line);
	}
	xclose(pipe_fd[WRITE_INDEX]);
	return (pipe_fd[READ_INDEX]);
}
