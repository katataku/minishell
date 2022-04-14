/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fullpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:29:18 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/14 14:38:14 by ahayashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

// This returns true if stat is success and path is a directory.
bool	is_directory(char *path)
{
	struct stat	path_stat;

	return (stat(path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode));
}

char	*get_fullpath_find_from_path(char	*filepath)
{
	if (is_directory(filepath))
		puterr_exit(filepath, strerror(EISDIR), STATUS_CAN_NOT_EXECUTE);
	if (access(filepath, X_OK) == 0)
		return (filepath);
	if (access(filepath, F_OK) == 0)
		puterr_exit(filepath, strerror(EACCES), STATUS_CAN_NOT_EXECUTE);
	perror(filepath);
	exit(STATUS_COMMAND_NOT_FOUND);
}

char	*get_fullpath_find_from_command(char **path, char *file_name)
{
	int		index;
	char	*fullpath;
	char	*file_name_with_slash;
	char	*found_filepath;

	index = 0;
	found_filepath = NULL;
	file_name_with_slash = ft_xstrjoin("/", file_name);
	while (path != NULL && path[index] != NULL)
	{
		fullpath = ft_xstrjoin(path[index], file_name_with_slash);
		if (!is_directory(fullpath))
		{
			if (access(fullpath, X_OK) == 0)
			{
				free(file_name_with_slash);
				return (fullpath);
			}
			if (found_filepath == NULL && access(fullpath, F_OK) == 0)
				found_filepath = ft_xstrdup(fullpath);
		}
		free(fullpath);
		index++;
	}
	if (found_filepath != NULL)
		puterr_exit(found_filepath, strerror(EACCES), STATUS_CAN_NOT_EXECUTE);
	else
		puterr_exit(file_name, "command not found", STATUS_COMMAND_NOT_FOUND);
	return (NULL);
}

char	*get_fullpath(char *file_name)
{
	char	**path;
	char	*env_path;

	if (ft_strchr(file_name, '/') != NULL)
		return (get_fullpath_find_from_path(file_name));
	env_path = get_env("PATH");
	if (env_path == NULL)
		return (get_fullpath_find_from_command(NULL, file_name));
	path = ft_xsplit(env_path, ':');
	free(env_path);
	return (get_fullpath_find_from_command(path, file_name));
}
