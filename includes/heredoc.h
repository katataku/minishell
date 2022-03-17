/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:10:04 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/15 16:29:16 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

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

char	*extract_quote(char *str);
bool	is_quoted(const char *str);
int		heredoc_read(t_exec_info *info);

#endif
