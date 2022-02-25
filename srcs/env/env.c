/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 13:57:50 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	free_keyvalue(t_keyvalue *kv)
{
	if (kv != NULL)
	{
		free(kv->key);
		free(kv->value);
		free(kv);
	}
}

t_list	**gen_env(void)
{
	static t_list	**env;

	if (env == NULL)
		env = (t_list **)ft_xcalloc(1, sizeof(t_list *));
	return (env);
}

void	init_env(void)
{
	t_list		**env;
	extern char	**environ;
	char		**cur_environ;
	char		*key_str;
	char		*value_str;

	cur_environ = environ;
	env = gen_env();
	while (*cur_environ != NULL)
	{
		key_str = ft_strdup(*cur_environ);
		value_str = ft_strchr(key_str, '=');
		*value_str = '\0';
		value_str++;
		set_env(key_str, value_str);
		free(key_str);
		cur_environ++;
	}
}
