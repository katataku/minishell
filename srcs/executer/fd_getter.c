/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_getter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:02:32 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:02:33 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	get_read_fd(t_exec_info *info, int i, int pipes[2][2])
{
	int		read_fd;

	if (i == 0)
	{
		if (info->srcfile != NULL)
			read_fd = xopen(info->srcfile, O_RDONLY, 0);
		else if (info->heredoc_word != NULL)
			read_fd = heredoc_read(info);
		else
			read_fd = STDIN_FILENO;
	}
	else
		read_fd = pipes[(i + 1) % 2][READ_INDEX];
	return (read_fd);
}

int	get_write_fd(t_exec_info *info, int i, int pipes[2][2])
{
	int		write_fd;

	if (i == info->cmd_num - 1)
	{
		if (info->dstfile != NULL)
			write_fd = xopen(info->dstfile, info->o_flag, 0644);
		else
			write_fd = STDOUT_FILENO;
	}
	else
	{
		xclose(pipes[i % 2][READ_INDEX]);
		write_fd = pipes[i % 2][WRITE_INDEX];
	}
	return (write_fd);
}
