/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:44:21 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/27 01:00:41 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_front(t_list **lst, t_list *newlst)
{
	if (lst == NULL || newlst == NULL)
		return ;
	newlst->next = *lst;
	*lst = newlst;
}
