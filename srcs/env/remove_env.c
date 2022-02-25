/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 15:08:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	lst_delone_in_lst(t_list **lst, t_list *delete_lst, void (*del)(void *))
{
	t_list		*cur_lst;

	if (lst == NULL || *lst == NULL)
		return ;
	if (*lst == delete_lst)
		*lst = (*lst)->next;
	else
	{
		cur_lst = (*lst);
		while (cur_lst->next != NULL)
		{
			if (cur_lst->next == delete_lst)
				cur_lst->next = delete_lst->next;
			cur_lst = cur_lst->next;
		}
	}
	ft_lstdelone(delete_lst, del);
}

void	unset_env(char *key)
{
	t_list		**env;
	t_list		*cur_env;

	env = gen_env();
	cur_env = *env;
	while (cur_env != NULL)
	{
		if (ft_strcmp(((t_keyvalue *)(cur_env->content))->key, key) == 0)
		{
			lst_delone_in_lst(env, cur_env, &free_keyvalue);
			return ;
		}
		cur_env = cur_env->next;
	}
}

void	remove_env(void)
{
	t_list		**env;

	env = gen_env();
	ft_lstclear(env, &free_keyvalue);
}
