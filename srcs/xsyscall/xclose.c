/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xclose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:02:47 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:02:47 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xsyscall.h"

int	xclose(int fildes)
{
	int	status;

	status = close(fildes);
	if (status == -1)
	{
		perror("close");
		exit(1);
	}
	return (status);
}
