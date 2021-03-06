/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:29:24 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/21 08:50:35 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*keyvalue_to_string(t_keyvalue *content)
{
	char	*str;
	char	*tmp;

	tmp = ft_xstrjoin(content->key, "=");
	str = ft_xstrjoin(tmp, content->value);
	free(tmp);
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
		envp[index] = keyvalue_to_string(current_env->content);
		index++;
		current_env = current_env->next;
	}
	return (envp);
}
