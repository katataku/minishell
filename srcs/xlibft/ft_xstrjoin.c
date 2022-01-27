/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:55:02 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/20 23:55:10 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "xlibft.h"

char	*ft_xstrjoin(const char *s1, const char *s2)
{
	char	*fullpath;

	fullpath = ft_strjoin(s1, s2);
	if (fullpath == NULL)
	{
		perror("malloc");
		exit(ERR_CODE_GENERAL);
	}
	return (fullpath);
}
