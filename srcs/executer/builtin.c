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

bool	is_builtin(char *cmd)
{
	return (ft_strcmp("echo", cmd) == 0);
}

int	execute_builtin(int argc, char **argv)
{
	if (ft_strcmp("echo", argv[0]) == 0)
		return (echo(argc, argv));
}
