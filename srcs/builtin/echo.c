/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:58:45 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/17 17:10:32 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	do_print(char **argv, bool is_print_linefeed)
{
	bool	is_first;

	is_first = true;
	while (*argv != NULL)
	{
		if (!is_first)
		{
			if (ft_putchar_fd(' ', STDOUT_FILENO) == -1)
				return (STATUS_FAILURE);
		}
		else
			is_first = false;
		if (ft_putstr_fd(*argv, STDOUT_FILENO) == -1)
			return (STATUS_FAILURE);
		argv++;
	}
	if (is_print_linefeed && ft_putchar_fd('\n', STDOUT_FILENO) == -1)
		return (STATUS_FAILURE);
	return (STATUS_SUCCESS);
}

/*
 * usage: echo [-n] arg...
 * Output the args separated by spaces, terminated with a newline. The return
 * status is 0 unless a write error occurs. If -n is specified, the trailing
 * newline is suppressed.
 */
int	builtin_echo(char **argv)
{
	bool	is_print_linefeed;

	is_print_linefeed = true;
	argv++;
	while (*argv != NULL && ft_strcmp("-n", *argv) == 0)
	{
		argv++;
		is_print_linefeed = false;
	}
	return (do_print(argv, is_print_linefeed));
}
