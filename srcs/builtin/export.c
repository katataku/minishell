/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 13:54:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	print_values(void)
{
	t_list		**env;
	t_list		*current_env;
	t_keyvalue	*kv;

	env = get_envlist();
	current_env = *env;
	while (current_env != NULL)
	{
		kv = current_env->content;
		if (ft_putstr_fd("export ", STDOUT_FILENO) == -1
			|| ft_putstr_fd(kv->key, STDOUT_FILENO) == -1
			|| ft_putstr_fd("=\"", STDOUT_FILENO) == -1
			|| ft_putstr_fd(kv->value, STDOUT_FILENO) == -1
			|| ft_putstr_fd("\"\n", STDOUT_FILENO) == -1)
			return (STATUS_FAILURE);
		current_env = current_env->next;
	}
	return (STATUS_SUCCESS);
}

static int	export_values(char **argv)
{
	char	*key;
	char	*value;
	int		return_status;

	return_status = STATUS_SUCCESS;
	while (*(++argv) != NULL)
	{
		key = ft_xstrdup(*argv);
		value = ft_strchr(key, '=');
		if (ft_isalpha(key[0]) || key[0] == '_')
		{
			if (value != NULL)
			{
				*value = '\0';
				set_env(key, ++value);
			}
			free(key);
			continue ;
		}
		return_status = STATUS_FAILURE;
		puterr("export", triple_join("`", *argv, "': not a valid identifier"));
		free(key);
	}
	return (return_status);
}

/*
 * usage: export [name[=value]]
 *
 * If no names are supplied, a list of names of all variables is displayed.
 * If names are supplied and a variable name is followed by =value, the value
 * of the variable is set to value. All the environment variables are to be
 * passed to child process in this shell.
 */
int	builtin_export(char **argv)
{
	if (argv[1] == NULL)
		return (print_values());
	else
		return (export_values(argv));
}
