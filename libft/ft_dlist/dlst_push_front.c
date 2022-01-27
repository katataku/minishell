/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_push_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:28:26 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/10 18:28:55 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	dlst_push_front(t_node	*head, t_node	*add)
{
	add->prev = head;
	add->next = head->next;
	head->next->prev = add;
	head->next = add;
}
