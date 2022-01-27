/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_create_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:29:13 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/10 18:40:12 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

/*
 * `prev` and `next` point a node itself that is created.
 */
t_node	*dlst_create_node(int num)
{
	t_node	*node;

	node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->prev = node;
	node->next = node;
	return (node);
}
