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

static void	ft_putdigit_fd(int n, int sign, int fd)
{
	char	c;

	if (sign * (n / 10) > 0)
		ft_putdigit_fd(n / 10, sign, fd);
	c = '0' + sign * (n % 10);
	ft_putchar_fd(c, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	ft_putdigit_fd(n, sign, fd);
}
