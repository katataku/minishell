/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:04:02 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 12:28:31 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	puterr(char *target, char *message)
{
	if (ft_putstr_fd(target, STDERR_FILENO) == -1)
		exit(STATUS_FAILURE);
	if (ft_putstr_fd(": ", STDERR_FILENO) == -1)
		exit(STATUS_FAILURE);
	if (ft_putendl_fd(message, STDERR_FILENO) == -1)
		exit(STATUS_FAILURE);
}

void	puterr_exit(char *target, char *message, int exit_status)
{
	puterr(target, message);
	exit(exit_status);
}
