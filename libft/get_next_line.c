/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:47:02 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/27 00:54:55 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_char(int fd, t_fd_info *info)
{
	if (info->read_bytes == 0 || info->index >= info->read_bytes)
	{
		info->read_bytes = read(fd, info->buf, BUFFER_SIZE);
		if (info->read_bytes < 0)
			return (GNL_ERR);
		if (info->read_bytes == 0)
			return (GNL_EOF);
		info->index = 0;
	}
	return (info->buf[info->index++]);
}

static void	*ft_realloc(void *ptr, size_t size)
{
	void	*rtv;
	size_t	i;

	if (ptr == NULL)
		return (ft_calloc(size, 1));
	rtv = malloc(size);
	if (rtv == NULL)
	{
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		if (i < size / 2)
			((unsigned char *)rtv)[i] = ((unsigned char *)ptr)[i];
		else
			((unsigned char *)rtv)[i] = 0;
		i++;
	}
	free(ptr);
	return (rtv);
}

// Try to double the memory size of ptr.
static size_t	grow_memory(char **ptr, size_t size)
{
	if (size == 0)
		size = INITIAL_ALLOCATE_SIZE;
	else
		size *= 2;
	*ptr = ft_realloc(*ptr, size);
	return (size);
}

static char	*return_with_free(char *rtv, char *line)
{
	free(line);
	return (rtv);
}

char	*get_next_line(int fd)
{
	static t_fd_info	fd_info = {0};
	char				*line;
	char				c;
	size_t				i;
	size_t				size;

	i = 0;
	size = 0;
	line = NULL;
	while (1)
	{
		c = get_char(fd, &fd_info);
		if (c == GNL_ERR)
			return (return_with_free(NULL, line));
		if (c == GNL_EOF)
			return (line);
		if (i + 1 >= size)
			size = grow_memory(&line, size);
		if (line == NULL)
			return (NULL);
		line[i] = c;
		if (c == '\n')
			return (line);
		i++;
	}
}
