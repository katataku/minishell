/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:04 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/24 17:09:52 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include "builtin.h"
# include "define.h"
# include "libft.h"
# include "xsyscall.h"

int		execute(t_exec_info *exec_info);
int		execute_builtin(int argc, char **argv);
int		execute_single_builtin(t_exec_info	*info);
bool	is_builtin(char *cmd);

#endif
