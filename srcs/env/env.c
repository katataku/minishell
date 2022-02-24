/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 07:35:17 by takkatao         ###   ########.fr       */
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
