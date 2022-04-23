/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:29:43 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/23 19:58:35 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	close_pipes(t_exec_info *info, int i, int pipes[2][2])
{
	if (i != 0)
		xclose(pipes[(i + 1) % 2][READ_INDEX]);
	if (i != info->cmd_num - 1 && info->cmd_num > 1)
		xclose(pipes[i % 2][WRITE_INDEX]);
}

static int	return_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit: 3", STDOUT_FILENO);
		return (STATUS_SIGNAL_BASE + WTERMSIG(status));
	}
	return (EXIT_FAILURE);
}

int	execute(t_exec_info *exec_info)
{
	int	*pid;
	int	pipes[2][2];
	int	i;
	int	status;

	expand_cmd(exec_info);
	if (exec_info->cmd_num == 1 && is_builtin(exec_info->cmds[0][0]))
		return (execute_single_builtin(exec_info));
	pid = (int *)ft_xcalloc(exec_info->cmd_num, sizeof(int));
	i = -1;
	set_signal_parent();
	while (++i < exec_info->cmd_num)
	{
		if (i != exec_info->cmd_num - 1)
			xpipe(pipes[i % 2]);
		pid[i] = xfork();
		if (pid[i] == 0)
			exec_child(exec_info, i, pipes);
		close_pipes(exec_info, i, pipes);
	}
	i = -1;
	while (++i < exec_info->cmd_num)
		xwaitpid(pid[i], &status, 0);
	free(pid);
	return (return_status(status));
}
