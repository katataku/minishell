/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/24 18:52:42 by takkatao         ###   ########.fr       */
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
		env = (t_list **)calloc(1, sizeof(t_list *));
	return (env);
}

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

void	set_env(char *name, char *value)
{
	t_list		**env;
	t_list		*cur_env;
	t_keyvalue	*content;

	env = gen_env();
	cur_env = *env;
	while (cur_env != NULL)
	{
		content = cur_env->content;
		if (ft_strcmp(content->key, name) == 0)
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
	content->key = ft_xstrdup(name);
	content->value = ft_xstrdup(value);
	ft_lstadd_back(env, ft_lstnew(content));
}

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
		ft_lstdelone(delete_env, free_keyvalue);
		return ;
	}
	while (cur_env->next != NULL)
	{
		if (ft_strcmp(((t_keyvalue *)(cur_env->next->content))->key, name) == 0)
		{
			delete_env = cur_env->next;
			cur_env->next = cur_env->next->next;
			ft_lstdelone(delete_env, free_keyvalue);
		}
		cur_env = cur_env->next;
	}
}
