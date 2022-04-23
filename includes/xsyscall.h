/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xsyscall.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:11:42 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 16:11:42 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XSYSCALL_H
# define XSYSCALL_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

int		xopen(const char *path, int oflag, int mode);
pid_t	xwaitpid(pid_t pid, int *stat_loc, int options);
int		xclose(int fildes);
int		xpipe(int fildes[2]);
pid_t	xfork(void);
int		xdup2(int fildes, int fildes2);
#endif
