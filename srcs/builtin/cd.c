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
 * Change the current working directory to given directory. If directory is not
 * supplied, the value of the HOME shell variable is used. `-` is not supported
 * as directory. Any additional arguments following directory are ignored.
 * If `..` appears in directory, it is processed by removing the immediately
 * preceding pathname component, back to a slash or the beginning of directory.
 * The return status is zero if the directory is successfully changed, non-zero
 * otherwise.
 */
int	cd(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);
}
