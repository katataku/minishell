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

int	execute(t_exec_info *exec_info)
{
	int	read_fd;
	int	write_fd;
	int	pid;

	pid = xfork();
	if (pid == 0)
	{
		read_fd = xopen(exec_info->srcfile, O_RDONLY, 0);
		write_fd = xopen(exec_info->dstfile, exec_info->o_flag, 0644);
		xdup2(read_fd, STDIN_FILENO);
		xdup2(write_fd, STDOUT_FILENO);
		execve(exec_info->cmds[0][0], exec_info->cmds[0], NULL);
		perror("execve");
	}
	return (0);
}
