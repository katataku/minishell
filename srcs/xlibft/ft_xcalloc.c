/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xcalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:48:23 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 12:28:31 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "xlibft.h"

char	*ft_xcalloc(size_t count, size_t size)
{
	char	*tmp;

	tmp = ft_calloc(count, size);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(STATUS_FAILURE);
	}
	return (tmp);
}
