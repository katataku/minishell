#include "executer.h"

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
		ft_putendl_fd(line, pipe_fd[WRITE_INDEX]);
	}
	xclose(pipe_fd[WRITE_INDEX]);
	return (pipe_fd[READ_INDEX]);
}
