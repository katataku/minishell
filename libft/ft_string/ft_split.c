/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:27:34 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 21:28:03 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	ft_count_splits(char const *s, char c)
{
	size_t	num;

	num = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			num++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (num);
}

static size_t	ft_split_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_split_strdup(const char **s, char c)
{
	size_t	len;
	char	*ptr;

	while (**s == c)
		(*s)++;
	len = ft_split_len(*s, c);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, *s, len + 1);
	*s += len;
	return (ptr);
}

static void	ft_free_all(char **ptr, size_t max_i)
{
	size_t	i;

	i = 0;
	while (i <= max_i)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	num;
	size_t	i;

	if (s == NULL)
		return (NULL);
	num = ft_count_splits(s, c);
	ptr = (char **) malloc(sizeof(char *) * (num + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < num)
	{
		ptr[i] = ft_split_strdup(&s, c);
		if (ptr[i] == NULL)
		{
			ft_free_all(ptr, i);
			return (NULL);
		}
		i++;
	}
	ptr[num] = NULL;
	return (ptr);
}
