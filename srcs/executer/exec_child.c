/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:56:32 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 19:57:54 by takkatao         ###   ########.fr       */
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

void	exec_child(t_exec_info *info, int i, int pipes[2][2])
{
	int		read_fd;
	int		write_fd;

	read_fd = get_read_fd(info, i, pipes);
	write_fd = get_write_fd(info, i, pipes);
	do_command(info->cmds[i], get_envp(), read_fd, write_fd);
}
