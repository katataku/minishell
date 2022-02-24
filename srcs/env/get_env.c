/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 07:34:18 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env(char *name)
{
	t_list		**env;
	t_list		*cur_env;
	t_keyvalue	*content;

	env = gen_env();
	cur_env = *env;
	while (cur_env != NULL)
	{
		content = cur_env->content;
		if (content->key != NULL && ft_strcmp(content->key, name) == 0)
			return (content->value);
		cur_env = cur_env->next;
	}
	return (NULL);
}
