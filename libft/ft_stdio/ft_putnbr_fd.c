/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:17:36 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 22:32:17 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

static int	do_putnbr(int n, int base, int fd)
{
	const char	digits[] = "9876543210123456789";
	char		buf[10];
	char		*p;
	int			len;

	p = &buf[10 - 1];
	*p-- = digits[n % base + 9];
	while (n / base != 0)
	{
		n /= base;
		*p-- = digits[n % base + 9];
	}
	len = &buf[10 - 1] - p;
	while (++p != &buf[10])
	{
		if (ft_putchar_fd(*p, fd) == -1)
			return (-1);
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	if (n < 0 && ft_putchar_fd('-', fd) == -1)
		return (-1);
	len = do_putnbr(n, 10, fd);
	if (len == -1)
		return (-1);
	if (n < 0)
		len += 1;
	return (len);
}
