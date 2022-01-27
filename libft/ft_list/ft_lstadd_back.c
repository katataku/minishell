/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:12:30 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/27 01:00:11 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*last;

	if (lst == NULL || newlst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = newlst;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = newlst;
}
