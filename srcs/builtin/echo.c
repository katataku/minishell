/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:58:45 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/24 10:58:45 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	echo(int argc, char **argv)
{
	bool	is_print_linefeed;
	bool	is_first;

	(void)argc;
	is_print_linefeed = true;
	is_first = true;
	argv++;
	if (*argv != NULL && ft_strcmp("-n", *argv) == 0)
	{
		argv++;
		is_print_linefeed = false;
	}
	while (*argv != NULL)
	{
		if (!is_first)
			ft_putchar_fd(' ', STDOUT_FILENO);
		else
			is_first = false;
		ft_putstr_fd(*argv, STDOUT_FILENO);
		argv++;
	}
	if (is_print_linefeed)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
