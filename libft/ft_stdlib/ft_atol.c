/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:15:57 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 22:21:30 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static long	_ft_atol(const char *str, int sign)
{
	unsigned long	cutoff;
	int				cutlim;
	unsigned long	acc;
	int				c;

	if (sign > 0)
		cutoff = LONG_MAX;
	else
		cutoff = -(unsigned long)LONG_MIN;
	cutlim = cutoff % 10;
	acc = 0;
	while (ft_isdigit(*str))
	{
		c = ft_todigit(*str);
		if (acc > cutoff / 10 || (acc == cutoff / 10 && c > cutlim))
			return (cutoff);
		acc = acc * 10 + c;
		str++;
	}
	return (acc * sign);
}

// If an overflow(underflow) occurs, return LONG_MAX(LONG_MIN).
// A cutlim value is 7 for LONG_MAX and 8 for LONG_MIN when the
// type of long is 64 bits.
long	ft_atol(const char *str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	return (_ft_atol(str, sign));
}
