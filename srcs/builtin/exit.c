/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:59:03 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/04 14:59:03 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	puterr_exit(char *target, char *message)
{
	if (ft_putstr_fd(target, STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd(": ", STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd(message, STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd("\n", STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
}

static bool	is_valid_exit_status(char *str)
{
	if (!ft_is_number(str))
		return (false);
	if (!ft_is_long_value(str))
		return (false);
	return (true);
}

/*
 * usage: exit [n]
 * Exit the shell, returning a status of n to the shell's parent. If n is
 * omitted, the exit status is that of the last command executed. If n is not
 * a valid number, the shell exit with 255. If more than two argument is given,
 * the shell not exit and return 1.
 */
int	builtin_exit(int argc, char **argv)
{
	(void)argc;
	if (ft_putendl_fd("exit", STDERR_FILENO) == -1)
		return (EXIT_FAILURE);
	if (argv[1] == NULL)
		exit (g_last_exit_status);
	if (!is_valid_exit_status(argv[1]))
	{
		puterr("exit", "numeric argument required");
	}
	if (argv[2] != NULL)
	{
		puterr("exit", "too many arguments");
		return (1);
	}
	exit(0);
}
