/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:06:23 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/27 01:00:11 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	if (lst == NULL || f == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	tail = head;
	lst = lst->next;
	while (lst != NULL)
	{
		tail->next = ft_lstnew(f(lst->content));
		if (tail->next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		tail = tail->next;
		lst = lst->next;
	}
	return (head);
}
