/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:19:37 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 12:16:07 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static int	cd_to_home(char **argv)
{
	char	*home_dir;

	home_dir = get_env("HOME");
	if (home_dir == NULL)
	{
		puterr(argv[0], "HOME not set");
		return (STATUS_CODE_FAILURE);
	}
	if (chdir(home_dir) == -1)
	{
		free(home_dir);
		perror(argv[0]);
		return (STATUS_CODE_FAILURE);
	}
	free(home_dir);
	return (STATUS_CODE_SUCCESS);
}

/*
 * usage: cd [directory]
 * Change the current working directory to given directory. If directory is not
 * supplied, the value of the HOME shell variable is used. `-` is not supported
 * as directory. Any additional arguments following directory are ignored.
 * The return status is zero if the directory is successfully changed, non-zero
 * otherwise.
 */
int	builtin_cd(char **argv)
{
	if (argv[1] == NULL)
		return (cd_to_home(argv));
	if (chdir(argv[1]) == -1)
	{
		perror(argv[0]);
		return (STATUS_CODE_FAILURE);
	}
	return (STATUS_CODE_SUCCESS);
}
