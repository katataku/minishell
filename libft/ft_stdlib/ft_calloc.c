/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:14:18 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 21:28:03 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	allocate;
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	allocate = count * size;
	if (allocate / count < size)
		return (NULL);
	ptr = malloc(allocate);
	if (ptr != NULL)
		ft_bzero(ptr, allocate);
	return (ptr);
}
