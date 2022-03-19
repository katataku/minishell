/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/19 13:21:36 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: unset
 * Always returns STATUS_SUCCESS.
 */
int	builtin_unset(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		unset_env(argv[i]);
		i++;
	}
	return (STATUS_SUCCESS);
}
