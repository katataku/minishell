/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:04 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 09:29:40 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "builtin.h"
# include "define.h"
# include "env.h"
# include "libft.h"
# include "utils.h"
# include "xsyscall.h"
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>

int		execute(t_exec_info *exec_info);
int		execute_builtin(int argc, char **argv);
int		execute_single_builtin(t_exec_info	*info);
bool	is_builtin(char *cmd);
char	*get_fullpath(char *file_name);

#endif
