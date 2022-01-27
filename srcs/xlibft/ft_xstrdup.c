/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:54:40 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/21 00:02:16 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "xlibft.h"

char	*ft_xstrdup(const char *s)
{
	char	*tmp;

	tmp = ft_strdup(s);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(ERR_CODE_GENERAL);
	}
	return (tmp);
}
