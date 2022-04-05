/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/05 17:11:03 by ahayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: export
 * Mark each name to be passed to child processes in the environment.
 * If a variable name is followed by =value, the value of the variable is set
 * to value. In this function, all the environment variables are to be passed
 * to child process.
 * The return status is zero unless one of the names is not a valid
 * shell variable name.
 */
int	builtin_export(char **argv)
{
	char	*key;
	char	*value;
	int		return_status;
	char	*message;

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
		message = triple_join("`", *argv, "': not a valid identifier");
		puterr("export", message);
		free(message);
		free(key);
	}
	return (return_status);
}
