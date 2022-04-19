/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipe.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:03:08 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:03:08 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xsyscall.h"

int	xpipe(int fildes[2])
{
	int	status;

	status = pipe(fildes);
	if (status == -1)
	{
		perror("pipe");
		exit(1);
	}
	return (status);
}
