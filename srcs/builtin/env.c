/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/27 14:34:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: env
 */
int	env(int argc, char **argv)
{
	t_list		**env;
	t_list		*current_env;
	t_keyvalue	*kv;

	(void)argc;
	(void)argv;
	env = get_envlist();
	current_env = *env;
	while (current_env != NULL)
	{
		kv = current_env->content;
		if (ft_putstr_fd(kv->key, STDOUT_FILENO) == -1
			|| ft_putstr_fd("=", STDOUT_FILENO) == -1
			|| ft_putstr_fd(kv->value, STDOUT_FILENO) == -1
			|| ft_putstr_fd("\n", STDOUT_FILENO) == -1)
			return (1);
		current_env = current_env->next;
	}
	return (0);
}
