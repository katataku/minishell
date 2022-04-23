/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:02:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 19:28:55 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xsyscall.h"

int	xdup(int fildes)
{
	int	status;

	status = dup(fildes);
	if (status == -1)
	{
		perror("dup");
		exit(1);
	}
	return (status);
}
