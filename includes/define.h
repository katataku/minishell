/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:33:34 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/23 15:13:40 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdbool.h>
# include <stdio.h>
# define READ_INDEX 0
# define WRITE_INDEX 1

# define STATUS_SUCCESS 0
# define STATUS_FAILURE 1
# define STATUS_MISUSE_BUILTIN 2
# define STATUS_CAN_NOT_EXECUTE 126
# define STATUS_COMMAND_NOT_FOUND 127
# define STATUS_SIGNAL_BASE 128

# define MAX_WORD_SIZE 4096

extern int	g_last_exit_status;

enum e_token
{
	T_NOTUSE,
	T_WORD,
	T_BAR,
	T_GT,
	T_GTGT,
	T_LT,
	T_LTLT,
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
	bool	is_syntaxerror;
}	t_exec_info;

typedef struct s_lexer_manager
{
	t_token		*token;
	int			token_index;
	int			word_index;
	char		word[MAX_WORD_SIZE];
	int			state;
	bool		is_misuse_builtin;
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
