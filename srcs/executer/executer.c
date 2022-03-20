/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:29:43 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/21 08:52:10 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	replace_fd(int old_fd, int new_fd)
{
	if (old_fd != new_fd)
	{
		xdup2(old_fd, new_fd);
		xclose(old_fd);
	}
}

static void	do_command(char **argv, char **env, int read_fd, int write_fd)
{
	replace_fd(read_fd, STDIN_FILENO);
	replace_fd(write_fd, STDOUT_FILENO);
	if (is_builtin(argv[0]))
		exit (execute_builtin(argv));
	execve(get_fullpath(argv[0]), argv, env);
	perror("execve");
	exit(STATUS_FAILURE);
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

	read_fd = get_read_fd(info, i, pipes);
	write_fd = get_write_fd(info, i, pipes);
	do_command(info->cmds[i], get_envp(), read_fd, write_fd);
}

/*
 * SIGQUITは特に何もしなくても無視されていそう
 * 子プロセス実行中は、親プロセスではSIGINTを無視する。
 */
void	set_signal_child(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
}

int	execute(t_exec_info *exec_info)
{
	int	pid;
	int	pipes[2][2];
	int	i;
	int	status;

	expand_cmd(exec_info);
	i = 0;
	if (exec_info->cmd_num == 1 && is_builtin(exec_info->cmds[0][0]))
		return (execute_single_builtin(exec_info));
	while (i < exec_info->cmd_num)
	{
		if (i != exec_info->cmd_num - 1)
			xpipe(pipes[i % 2]);
		pid = xfork();
		if (pid == 0)
			exec_child(exec_info, i, pipes);
		else
			set_signal_child();
		close_pipes(exec_info, i, pipes);
		i++;
	}
	xwaitpid(pid, &status, 0);
	return (status);
}
