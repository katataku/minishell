/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_pop_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:28:22 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/10 18:28:40 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_node	*dlst_pop_back(t_node	*head)
{
	t_node	*pop;

	pop = head->prev;
	head->prev = pop->prev;
	pop->prev->next = head;
	pop->prev = NULL;
	pop->next = NULL;
	return (pop);
}
