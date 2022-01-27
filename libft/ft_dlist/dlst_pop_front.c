/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_pop_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:08 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/10 18:24:31 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_node	*dlst_pop_front(t_node	*head)
{
	t_node	*pop;

	pop = head->next;
	head->next = pop->next;
	pop->next->prev = head;
	pop->prev = NULL;
	pop->next = NULL;
	return (pop);
}
