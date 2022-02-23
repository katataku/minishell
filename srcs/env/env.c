/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/23 09:55:28 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_kvlist	**gen_env(void)
{
	static t_kvlist	**env;

	if (env == NULL)
	{
		env = (t_kvlist **)calloc(1, sizeof(t_kvlist *));
		*env = (t_kvlist *)ft_xcalloc(1, sizeof(t_kvlist));
	}
	return (env);
}

char	*get_env(char *name)
{
	t_kvlist	**env;
	t_kvlist	*cur_env;

	env = gen_env();
	cur_env = *env;
	while (cur_env != NULL)
	{
		if (cur_env->key != NULL && ft_strcmp(cur_env->key, name) == 0)
			return (cur_env->value);
		cur_env = cur_env->next;
	}
	return (NULL);
}

void	set_env(char *name, char *value)
{
	t_kvlist	**env;
	t_kvlist	*cur_env;

	env = gen_env();
	cur_env = *env;
	while (cur_env->key != NULL)
	{
		if (ft_strcmp(cur_env->key, name) == 0)
		{
			free(cur_env->value);
			cur_env->value = ft_xstrdup(value);
			return ;
		}
		if (cur_env->next == NULL)
		{
			cur_env->next = (t_kvlist *)ft_xcalloc(1, sizeof(t_kvlist));
			cur_env = cur_env->next;
			break ;
		}
		cur_env = cur_env->next;
	}
	cur_env->key = ft_xstrdup(name);
	cur_env->value = ft_xstrdup(value);
}

void	remove_env(char *name)
{
	t_kvlist	**env;
	t_kvlist	*cur_env;
	t_kvlist	*delete_env;

	env = gen_env();
	cur_env = *env;
	delete_env = NULL;
	if (cur_env->key && ft_strcmp(cur_env->key, name) == 0)
	{
		delete_env = *env;
		*env = (*env)->next;
	}
	while (cur_env->next != NULL)
	{
		if (cur_env->next->key && ft_strcmp(cur_env->next->key, name) == 0)
			delete_env = cur_env->next;
		if (cur_env->next->key && ft_strcmp(cur_env->next->key, name) == 0)
			cur_env->next = cur_env->next->next;
		cur_env = cur_env->next;
	}
	if (delete_env == NULL)
		return ;
	free(delete_env->key);
	free(delete_env->value);
	free(delete_env);
}
