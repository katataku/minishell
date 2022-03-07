/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:48:23 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/25 14:08:04 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xlibft.h"

t_list	*ft_xlstnew(void *content)
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	if (tmp == NULL)
	{
		perror("malloc");
		exit(STATUS_FAILURE);
	}
	return (tmp);
}
