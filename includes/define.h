/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:33:34 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/11 12:33:34 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdbool.h>
# include <stdio.h>
# define READ_INDEX 0
# define WRITE_INDEX 1

# define ERR_CODE_GENERAL 1
# define ERR_CODE_CAN_NOT_EXECUTE 126
# define ERR_CODE_COMMAND_NOT_FOUND 127

enum e_token
{
	T_WORD,
	T_BAR,
	T_SEMI,
	T_GT,
	T_GTGT,
	T_LT,
	T_LTLT,
	T_SQ,
	T_DQ,
	T_BQ,
	T_DOLLAR,
	T_C_BRA_OPN,
	T_C_BRA_CLS
};

typedef struct s_token
{
	int		*token;
	char	**word;
}	t_token;

typedef struct s_exec_info
{
	char	***cmds;
	char	*srcfile;
	char	*dstfile;
	int		o_flag;
}	t_exec_info;

#endif
