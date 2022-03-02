/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:56:18 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/01 18:15:15 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "libft.h"
# include <stdbool.h>
# include "env.h"

// NOTE: 引数にargcはなくても良いかもしれない。他のbuiltinの様子も見て判断
int	echo(int argc, char **argv);
int	env(int argc, char **argv);
int	pwd(int argc, char **argv);
int	unset(int argc, char **argv);

#endif
