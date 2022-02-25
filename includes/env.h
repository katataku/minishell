/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:24:54 by takkatao          #+#    #+#             */
/*   Updated: 2022/02/25 13:23:31 by takkatao         ###   ########.fr       */
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

void	init_env(void);
void	free_keyvalue(t_keyvalue *kv);
t_list	**gen_env(void);
char	*get_env(char *name);
void	set_env(char *name, char *value);
void	remove_env(char *name);
void	remove_all_env(void);

#endif
