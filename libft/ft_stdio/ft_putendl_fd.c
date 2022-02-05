/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:11:00 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/01 12:01:42 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	len;

	if (s == NULL)
		return (-1);
	len = ft_putstr_fd(s, fd);
	if (len == -1)
		return (-1);
	if (ft_putchar_fd('\n', fd) == -1)
		return (-1);
	return (len + 1);
}
