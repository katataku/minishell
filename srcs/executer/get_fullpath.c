#include "executer.h"

void	puterr_exit(char *target, char *message, int exit_status)
{
	if (ft_putstr_fd(target, 2) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd(": ", 2) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd(message, 2) == -1)
		exit(ERR_CODE_GENERAL);
	if (ft_putstr_fd("\n", 2) == -1)
		exit(ERR_CODE_GENERAL);
	exit(exit_status);
}

char	*get_fullpath_find_from_path(char	*filepath)
{
	if (access(filepath, X_OK) == 0)
		return (filepath);
	if (access(filepath, F_OK) == 0)
		puterr_exit(filepath, strerror(EACCES), ERR_CODE_CAN_NOT_EXECUTE);
	perror(filepath);
	exit(ERR_CODE_COMMAND_NOT_FOUND);
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
	while (path[index] != NULL)
	{
		fullpath = ft_xstrjoin(path[index], file_name_with_slash);
		if (access(fullpath, X_OK) == 0)
			return (fullpath);
		if (found_filepath == NULL && access(fullpath, F_OK) == 0)
			found_filepath = ft_xstrdup(fullpath);
		index++;
	}
	if (found_filepath != NULL)
		puterr_exit(found_filepath, strerror(EACCES), ERR_CODE_CAN_NOT_EXECUTE);
	else
		puterr_exit(file_name, "command not found", ERR_CODE_COMMAND_NOT_FOUND);
	return (NULL);
}

char	*get_fullpath(char *file_name)
{
	char	**path;

	if (ft_strchr(file_name, '/') != NULL)
		return (get_fullpath_find_from_path(file_name));
	path = ft_xsplit(get_env("PATH"), ':');
	return (get_fullpath_find_from_command(path, file_name));
}
