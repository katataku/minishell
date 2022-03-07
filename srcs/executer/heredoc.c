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

int	heredoc_read(t_exec_info *info)
{
	int		pipe_fd[2];
	char	*line;

	xpipe(pipe_fd);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || ft_strcmp(line, info->heredoc_word) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(expand_env(line), pipe_fd[WRITE_INDEX]);
	}
	xclose(pipe_fd[WRITE_INDEX]);
	return (pipe_fd[READ_INDEX]);
}
