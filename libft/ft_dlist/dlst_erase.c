/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_erase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 02:34:30 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/11 02:34:44 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	dlst_erase(t_node *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	node = NULL;
}
