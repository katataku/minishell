/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:54:17 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/20 23:54:18 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "xlibft.h"

char	**ft_xsplit(const char *s, char c)
{
	char	**tmp;

	tmp = ft_split(s, c);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(ERR_CODE_GENERAL);
	}
	return (tmp);
}
