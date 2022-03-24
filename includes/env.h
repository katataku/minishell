/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:24:54 by takkatao          #+#    #+#             */
/*   Updated: 2022/03/20 14:32:38 by takkatao         ###   ########.fr       */
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
void	free_keyvalue(void *kv);
t_list	**gen_env(void);
char	*get_env(char *key);
char	*get_env_key(char *word);
t_list	**get_envlist(void);
char	**get_envp(void);
void	set_env(char *key, char *value);
void	unset_env(char *key);
void	remove_env(void);

#endif
