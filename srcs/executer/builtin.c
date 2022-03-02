/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:43 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/02 15:20:50 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// NOTE: execute.cでも使用しているので別途切り出しても良いかもしれない
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
	return (ft_strcmp("cd", cmd) == 0
		|| ft_strcmp("echo", cmd) == 0
		|| ft_strcmp("env", cmd) == 0
		|| ft_strcmp("pwd", cmd) == 0
		|| ft_strcmp("unset", cmd) == 0);
}

int	execute_builtin(int argc, char **argv)
{
	if (ft_strcmp("cd", argv[0]) == 0)
		return (cd(argc, argv));
	if (ft_strcmp("echo", argv[0]) == 0)
		return (echo(argc, argv));
	if (ft_strcmp("env", argv[0]) == 0)
		return (env(argc, argv));
	if (ft_strcmp("pwd", argv[0]) == 0)
		return (pwd(argc, argv));
	if (ft_strcmp("unset", argv[0]) == 0)
		return (unset(argc, argv));
	return (1);
}

int	execute_single_builtin(t_exec_info	*info)
{
	int	save_stdout;
	int	save_stdin;
	int	exit_status;
	int	tmp_fd;

	save_stdout = STDOUT_FILENO;
	save_stdin = STDIN_FILENO;
	if (info->dstfile != NULL)
	{
		save_stdout = dup(STDOUT_FILENO);
		tmp_fd = xopen(info->dstfile, O_RDWR | O_CREAT, 0644);
		replace_fd(tmp_fd, STDOUT_FILENO);
	}
	if (info->srcfile != NULL)
	{
		save_stdout = dup(STDIN_FILENO);
		tmp_fd = xopen(info->srcfile, O_RDONLY, 0);
		replace_fd(tmp_fd, STDIN_FILENO);
	}
	exit_status = execute_builtin(-1, info->cmds[0]);
	replace_fd(save_stdout, STDOUT_FILENO);
	replace_fd(save_stdin, STDIN_FILENO);
	return (exit_status);
}
