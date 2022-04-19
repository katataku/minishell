/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xopen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:03:04 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:03:05 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xsyscall.h"

int	xopen(const char *path, int oflag, int mode)
{
	int	fd;

	fd = open(path, oflag, mode);
	if (fd < 0)
	{
		perror(path);
		exit(1);
	}
	return (fd);
}
