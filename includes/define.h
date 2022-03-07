/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:33:34 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/07 09:21:11 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdbool.h>
# include <stdio.h>
# define READ_INDEX 0
# define WRITE_INDEX 1

# define ERR_CODE_GENERAL 1
# define ERR_CODE_MISUSE_BUILTIN 2
# define ERR_CODE_CAN_NOT_EXECUTE 126
# define ERR_CODE_COMMAND_NOT_FOUND 127

extern int	g_last_exit_status;

enum e_token
{
	T_NOTUSE,
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
	int		cmd_num;
	char	*srcfile;
	char	*heredoc_word;
	char	*dstfile;
	int		o_flag;
}	t_exec_info;

typedef struct s_lexer_manager
{
	t_token		*token;
	int			token_index;
	int			word_index;
	char		word[4097];
	int			state;
}	t_lexer_manager;

enum e_lexer_state
{
	NEUTRAL,
	IN_CBRACKET,
	IN_SQUOTE,
	IN_DQUOTE,
	IN_BQUOTE
};

#endif
