/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:43:48 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/15 11:43:48 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

//char	*ft_replace(char *str, char *before, char *after)
//{
//	char	*p;
//	char	*found;
//	char	*remain;
//	size_t	new_len;
//
//	found = ft_strstr(str, before);
//	if (found == NULL)
//		return (str);
//	remain = found + ft_strlen(before);
//	new_len = ft_strlen(str) - ft_strlen(before) + ft_strlen(after);
//	p = malloc(new_len + 1);
//	ft_memcpy(p, str, found - str);
//	ft_memcpy(p + (found - str), after, ft_strlen(after));
//	ft_memcpy(p + (found - str) + ft_strlen(after), remain, ft_strlen(remain));
//	p[new_len] = '\0';
//	free(str);
//	return (p);
//}

char	*get_var_name(char *word)
{
	(void)word;
	return (ft_strdup("$HOME"));
}

char	*super_join(char *first, char *second, char *third)
{
	char *str;

	str = ft_xstrjoin(first, ft_xstrjoin(second, third));
	free(first);
	return (str);
}

char	*expand(char *word)
{
	char	*name;
	size_t	i;

	i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '$')
		{
			name = get_var_name(word[i]);
			word[i] = '\0';
			word = super_join(word, get_env(&name[1]), word + i + ft_strlen(name));
			continue;
		}
		i++;
	}
	return (word);
}
