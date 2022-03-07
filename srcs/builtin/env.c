/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/07 12:16:39 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: env
 */
int	builtin_env(char **argv)
{
	t_list		**env;
	t_list		*current_env;
	t_keyvalue	*kv;

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
			return (STATUS_CODE_FAILURE);
		current_env = current_env->next;
	}
	return (STATUS_CODE_SUCCESS);
}
