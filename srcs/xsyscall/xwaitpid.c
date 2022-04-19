/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwaitpid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:03:12 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/19 16:03:12 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xsyscall.h"

pid_t	xwaitpid(pid_t pid, int *stat_loc, int options)
{
	pid_t	ret;

	ret = waitpid(pid, stat_loc, options);
	if (ret == -1)
	{
		perror("waitpid");
		exit(1);
	}
	return (ret);
}
