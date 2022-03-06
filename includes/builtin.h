/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:56:18 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/06 16:23:24 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include "env.h"
# include "unistd.h"

// NOTE: 引数にargcはなくても良いかもしれない。他のbuiltinの様子も見て判断
int	cd(int argc, char **argv);
int	echo(int argc, char **argv);
int	env(int argc, char **argv);
int	builtin_export(int argc, char **argv);
int	pwd(int argc, char **argv);
int	unset(int argc, char **argv);

#endif
