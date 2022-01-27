/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:45:55 by ahayashi          #+#    #+#             */
/*   Updated: 2022/01/26 21:28:03 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (len > 0 && ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	while (len > 0 && ft_strchr(set, s1[start]) != NULL)
	{
		len--;
		start++;
	}
	return (ft_substr(s1, start, len));
}
