/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:29:24 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/20 19:21:03 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_keyvalue_string(t_keyvalue *content)
{
	char	*str;

	str = content->key;
	str = ft_xstrjoin(str, "=");
	str = ft_xstrjoin(str, content->value);
	return (str);
}

char	**get_envp(void)
{
	char		**envp;
	t_list		**env;
	t_list		*current_env;
	int			index;

	env = gen_env();
	current_env = *env;
	envp = (char **)ft_xcalloc(ft_lstsize(*env) + 1, sizeof(char *));
	index = 0;
	while (current_env != NULL)
	{
		envp[index] = get_keyvalue_string(current_env->content);
		index++;
		current_env = current_env->next;
	}
	return (envp);
}
