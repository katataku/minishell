/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:19:37 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/02 15:19:37 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: cd [directory]
 * Change the current working directory to the given directory. If directory is
 * not supplied, the value of the HOME shell variable is used. Any additional
 * arguments following directory are ignored. The return status is zero if the
 * directory is successfully changed, non-zero otherwise.
 */
int	cd(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
