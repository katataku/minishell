/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:51:05 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/11 02:55:41 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include "ft_stdlib.h"

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

void	dlst_assign(t_node *node, int num);
t_node	*dlst_create_node(int num);
void	dlst_erase(t_node *node);
t_node	*dlst_pop_back(t_node	*head);
t_node	*dlst_pop_front(t_node	*head);
void	dlst_push_back(t_node	*head, t_node	*add);
void	dlst_push_front(t_node	*head, t_node	*add);
#endif
