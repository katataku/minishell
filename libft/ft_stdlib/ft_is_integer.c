/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:57:01 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/28 15:57:01 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int	ft_is_integer(char *str)
{
	long	num;

	num = ft_atol(str);
	return (num >= INT_MIN && num <= INT_MAX);
}
