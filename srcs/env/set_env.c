/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 15:09:17 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_env(char *key, char *value)
{
	t_list		**env;
	t_list		*cur_env;
	t_keyvalue	*content;

	env = gen_env();
	cur_env = *env;
	while (cur_env != NULL)
	{
		content = cur_env->content;
		if (ft_strcmp(content->key, key) == 0)
		{
			free(content->value);
			content->value = ft_xstrdup(value);
			return ;
		}
		if (cur_env->next == NULL)
			break ;
		cur_env = cur_env->next;
	}
	content = (t_keyvalue *)ft_xcalloc(1, sizeof(t_keyvalue));
	content->key = ft_xstrdup(key);
	content->value = ft_xstrdup(value);
	ft_lstadd_back(env, ft_xlstnew(content));
}
