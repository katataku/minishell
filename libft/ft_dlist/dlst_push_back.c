/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:28:25 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/10 18:28:47 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void	dlst_push_back(t_node	*head, t_node	*add)
{
	add->prev = head->prev;
	add->next = head;
	head->prev->next = add;
	head->prev = add;
}
