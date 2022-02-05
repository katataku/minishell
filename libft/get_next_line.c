/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:47:02 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/31 21:24:17 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_char(int fd, t_fd_info *info)
{
	if (info->read_bytes == 0 || info->index >= info->read_bytes)
	{
		info->read_bytes = read(fd, info->buf, BUFFER_SIZE);
		if (info->read_bytes < 0)
			return (GETC_ERR);
		if (info->read_bytes == 0)
			return (GETC_EOF);
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

static int	return_with_free(int rtv, char *ptr)
{
	free(ptr);
	return (rtv);
}

// If successful, the number of bytes actually read is returned.
// Upon reading end-of-file, zero is returned. Otherwise, a -1 is returned.
int	get_next_line(int fd, char **line)
{
	static t_fd_info	fd_info;
	char				c;
	size_t				i;
	size_t				size;

	i = 0;
	size = 0;
	if (line == NULL)
		return (-1);
	*line = NULL;
	while (1)
	{
		c = get_char(fd, &fd_info);
		if (c == GETC_ERR)
			return (return_with_free(-1, *line));
		if (c == GETC_EOF)
			return (i);
		if (i + 1 >= size)
			size = grow_memory(line, size);
		if (*line == NULL)
			return (-1);
		(*line)[i++] = c;
		if (c == '\n')
			return (i);
	}
}
