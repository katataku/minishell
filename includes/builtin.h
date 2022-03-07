/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:56:18 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 11:54:48 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "env.h"
# include "define.h"
# include "utils.h"
# include "unistd.h"

int	builtin_cd(char **argv);
int	builtin_echo(char **argv);
int	builtin_env(char **argv);
int	builtin_exit(char **argv);
int	builtin_export(char **argv);
int	builtin_pwd(char **argv);
int	builtin_unset(char **argv);

#endif
