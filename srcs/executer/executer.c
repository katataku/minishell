/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:29:43 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/11 17:29:43 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	replace_fd(int old_fd, int new_fd)
{
	xdup2(old_fd, new_fd);
	xclose(old_fd);
}

static void	do_command(char **argv, char **env, int read_fd, int write_fd)
{
	replace_fd(read_fd, STDIN_FILENO);
	replace_fd(write_fd, STDOUT_FILENO);
	execve(argv[0], argv, env);
	perror("execve");
	exit(ERR_CODE_GENERAL);
}

static void	close_pipes(t_exec_info *info, int i, int pipes[2][2])
{
	if (i != 0)
		xclose(pipes[(i + 1) % 2][READ_INDEX]);
	if (i != info->cmd_num - 1 && info->cmd_num > 1)
		xclose(pipes[i % 2][WRITE_INDEX]);
}

static void	exec_child(t_exec_info *info, int i, int pipes[2][2])
{
	int		read_fd;
	int		write_fd;

	if (i == 0)
		read_fd = xopen(info->srcfile, O_RDONLY, 0);
	else
		read_fd = pipes[(i + 1) % 2][READ_INDEX];
	if (i == info->cmd_num - 1)
		write_fd = xopen(info->dstfile, info->o_flag, 0644);
	else
	{
		xclose(pipes[i % 2][READ_INDEX]);
		write_fd = pipes[i % 2][WRITE_INDEX];
	}
	do_command(info->cmds[i], NULL, read_fd, write_fd);
}

int	execute(t_exec_info *exec_info)
{
	int	pid;
	int	pipes[2][2];
	int	i;
	int	status;

	i = 0;
	while (i < exec_info->cmd_num)
	{
		if (i != exec_info->cmd_num - 1)
			xpipe(pipes[i % 2]);
		pid = xfork();
		if (pid == 0)
			exec_child(exec_info, i, pipes);
		close_pipes(exec_info, i, pipes);
		i++;
	}
	xwaitpid(pid, &status, 0);
	return (status);
}
