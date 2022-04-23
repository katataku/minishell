/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:11:50 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 16:11:50 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "define.h"
# include "utils.h"
# include "xlibft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void		free_exec_info(t_exec_info *exec_info);
t_exec_info	*parser(t_token *token);

#endif
