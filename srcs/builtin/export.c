/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:20:52 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/03 10:11:10 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/*
 * usage: unset
 */
int	export(int argc, char **argv)
{
	char	*key;
	char	*value;
	int		i;

	(void)argc;
	i = 1;
	while (argv[i] != NULL)
	{
		key = ft_xstrdup(argv[i]);
		value = ft_strchr(key, '=');
		if (value != NULL)
		{
			*value = '\0';
			value++;
			set_env(key, value);
		}
		i++;
	}
	return (0);
}
