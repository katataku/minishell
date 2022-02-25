/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 13:40:55 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	remove_env(char *name)
{
	t_list		**env;
	t_list		*cur_env;
	t_list		*delete_env;

	env = gen_env();
	cur_env = *env;
	if (ft_strcmp(((t_keyvalue *)(cur_env->content))->key, name) == 0)
	{
		delete_env = *env;
		*env = (*env)->next;
		ft_lstdelone(delete_env, (void (*)(void *)) & free_keyvalue);
		return ;
	}
	while (cur_env->next != NULL)
	{
		if (ft_strcmp(((t_keyvalue *)(cur_env->next->content))->key, name) == 0)
		{
			delete_env = cur_env->next;
			cur_env->next = cur_env->next->next;
			ft_lstdelone(delete_env, (void (*)(void *)) & free_keyvalue);
		}
		cur_env = cur_env->next;
	}
}

void	remove_all_env(void)
{
	t_list		**env;

	env = gen_env();
	ft_lstclear(env, (void (*)(void *)) & free_keyvalue);
}
