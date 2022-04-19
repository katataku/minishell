/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdup2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:02:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:02:54 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xsyscall.h"

int	xdup2(int fildes, int fildes2)
{
	int	status;

	status = dup2(fildes, fildes2);
	if (status == -1)
	{
		perror("dup2");
		exit(1);
	}
	return (status);
}
