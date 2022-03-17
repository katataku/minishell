/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:52:12 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/15 15:52:12 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
 * Replace the first found the before string with the after string. If the
 * before string is not found, str is returned. Otherwise, a new string are
 * created and str is freed.
 */
char	*ft_replace(char *str, char *before, char *after)
{
	char	*p;
	char	*found;
	char	*remain;
	size_t	new_len;

	found = ft_strstr(str, before);
	if (found == NULL)
		return (str);
	remain = found + ft_strlen(before);
	new_len = ft_strlen(str) - ft_strlen(before) + ft_strlen(after);
	p = malloc(new_len + 1);
	ft_memcpy(p, str, found - str);
	ft_memcpy(p + (found - str), after, ft_strlen(after));
	ft_memcpy(p + (found - str) + ft_strlen(after), remain, ft_strlen(remain));
	p[new_len] = '\0';
	free(str);
	return (p);
}
