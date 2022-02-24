/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:43 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/24 17:08:43 by ahayashi         ###   ########.jp       */
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

bool	is_builtin(char *cmd)
{
	return (ft_strcmp("echo", cmd) == 0);
}

int	execute_builtin(int argc, char **argv)
{
	int	save_stdout;
	int	exit_status;

	save_stdout = dup(STDOUT_FILENO);
	int fd = xopen("actual", O_RDWR | O_CREAT, 0644);
	replace_fd(fd, STDOUT_FILENO);
	close(fd);
	if (ft_strcmp("echo", argv[0]) == 0)
		exit_status = echo(argc, argv);
	replace_fd(save_stdout, STDOUT_FILENO);
	return (exit_status);
}
