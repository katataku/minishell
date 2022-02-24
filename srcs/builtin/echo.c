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
	bool	isPrintLineFeed;
	bool	isFirst;

	(void)argc;
	isPrintLineFeed = true;
	isFirst = true;
	argv++;
	if (*argv != NULL && ft_strcmp("-n", *argv) == 0)
	{
		argv++;
		isPrintLineFeed = false;
	}
	while (*argv != NULL)
	{
		if (!isFirst)
			ft_putchar_fd(' ', STDOUT_FILENO);
		else
			isFirst = false;
		ft_putstr_fd(*argv, STDOUT_FILENO);
		argv++;
	}
	if (isPrintLineFeed)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
