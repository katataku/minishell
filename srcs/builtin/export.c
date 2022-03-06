/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/06 16:09:10 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// getfullpathにあるputerr_exitといい感じにutili的なところに置きたいかもしれない
static void	puterr(char *target, char *message)
{
	if (ft_putstr_fd(target, STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd(": ", STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd(message, STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd("\n", STDERR_FILENO) == -1)
		exit(ERR_CODE_GENERAL);
}

/*
 * usage: export
 * Mark each name to be passed to child processes in the environment.
 * If a variable name is followed by =value, the value of the variable is set
 * to value. In this function, all the environment variables are to be passed
 * to child process.
 * The return status is zero unless one of the names is not a valid
 * shell variable name.
 */
int	export_env(int argc, char **argv)
{
	char	*key;
	char	*value;
	int		return_status;

	(void)argc;
	return_status = 0;
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
			continue ;
		}
		return_status = 1;
		puterr("export", ft_xstrjoin("`",
				ft_xstrjoin(*argv, "': not a valid identifier")));
	}
	return (return_status);
}
