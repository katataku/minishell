/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:47:01 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/31 15:47:01 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*triple_join(char *s1, char *s2, char *s3)
{
	char	*rtv;
	char	*tmp;

	tmp = ft_xstrjoin(s1, s2);
	rtv = ft_xstrjoin(tmp, s3);
	free(tmp);
	return (rtv);
}
