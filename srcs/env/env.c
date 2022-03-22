/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:00 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 15:28:04 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_env_key(char *word)
{
	size_t	i;

	if (ft_strcmp("$?", word) == 0)
		return (ft_xstrdup("?"));
	if (word[0] != '$')
		return (NULL);
	if (!ft_isalpha(word[1]) && word[1] != '_')
		return (NULL);
	i = 2;
	while (ft_isalnum(word[i]) || word[i] == '_')
	{
		i++;
	}
	return (ft_substr(word, 1, i - 1));
}

void	free_keyvalue(void *input)
{
	t_keyvalue	*kv;

	kv = input;
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
	{
		env = (t_list **)ft_xcalloc(1, sizeof(t_list *));
		init_env();
	}
	return (env);
}

void	init_env(void)
{
	extern char	**environ;
	char		**cur_environ;
	char		*key_str;
	char		*value_str;

	cur_environ = environ;
	while (*cur_environ != NULL)
	{
		key_str = ft_xstrdup(*cur_environ);
		value_str = ft_strchr(key_str, '=');
		*value_str = '\0';
		value_str++;
		set_env(key_str, value_str);
		free(key_str);
		cur_environ++;
	}
}
