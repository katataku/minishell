/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:47:25 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 22:50:55 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef INITIAL_ALLOCATE_SIZE
#  define INITIAL_ALLOCATE_SIZE 8
# endif

# define GNL_EOF -1
# define GNL_ERR -2

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_info
{
	char	buf[BUFFER_SIZE];
	ssize_t	index;
	ssize_t	read_bytes;
}	t_fd_info;

char	*get_next_line(int fd);
#endif
