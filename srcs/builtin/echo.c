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

#include <stdbool.h>
#include "builtin.h"

int	echo(int argc, char **argv)
{
	bool	isPrintLineFeed;
	bool	isFirst;

	isPrintLineFeed = true;
	isFirst = true;
	argv++;
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
