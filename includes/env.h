/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:24:54 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/24 18:50:51 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "define.h"
# include "xlibft.h"

typedef struct s_keyvalue
{
	char			*key;
	char			*value;
}	t_keyvalue;

char	*get_env(char *name);
void	set_env(char *name, char *value);
void	remove_env(char *name);

#endif
