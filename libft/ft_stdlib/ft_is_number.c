/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:55:29 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/28 15:55:29 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

int	ft_is_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	str++;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
