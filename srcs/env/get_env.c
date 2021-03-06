/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 15:10:13 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env(char *key)
{
	t_list		**env;
	t_list		*cur_env;
	t_keyvalue	*content;

	if (ft_strcmp("?", key) == 0)
		return (ft_itoa(g_last_exit_status));
	env = gen_env();
	cur_env = *env;
	while (cur_env != NULL)
	{
		content = cur_env->content;
		if (content->key != NULL && ft_strcmp(content->key, key) == 0)
			return (ft_xstrdup(content->value));
		cur_env = cur_env->next;
	}
	return (NULL);
}
