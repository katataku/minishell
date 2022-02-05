/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:47:25 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/31 21:24:17 by ahayashi         ###   ########.jp       */
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

# define GETC_EOF -1
# define GETC_ERR -2

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_info
{
	char	buf[BUFFER_SIZE];
	ssize_t	index;
	ssize_t	read_bytes;
}	t_fd_info;

int	get_next_line(int fd, char **line);

#endif
