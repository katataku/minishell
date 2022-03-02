/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:30:24 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/02 14:30:24 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"


/*
 * usage: pwd
 * Print the absolute pathname of the current working directory. The return
 * status is zero unless an error is encountered while determining the name of
 * the current directory.
 */
int	pwd(int argc, char **argv)
{
	char	*pwd;

	(void)argc;
	(void)argv;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (1);
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (0);
}
