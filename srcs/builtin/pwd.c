/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:30:24 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 12:16:54 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: pwd
 * Print the absolute pathname of the current working directory. The return
 * status is zero unless an error is encountered while determining the name of
 * the current directory.
 */
int	builtin_pwd(char **argv)
{
	char	*pwd;

	(void)argv;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (STATUS_FAILURE);
	ft_putendl_fd(pwd, STDOUT_FILENO);
	free(pwd);
	return (STATUS_SUCCESS);
}
