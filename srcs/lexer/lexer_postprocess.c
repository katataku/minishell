/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_postprocess.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:50:53 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 16:51:05 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	lexer_postprocess(t_lexer_manager	*mgr)
{
	if (mgr->is_misuse_builtin || mgr->state != NEUTRAL)
	{
		g_last_exit_status = STATUS_MISUSE_BUILTIN;
		puterr("minishell", "syntax error");
		free_lexer_token(mgr->token);
		mgr->token = NULL;
	}
	if (mgr->token_index == 0)
	{
		free_lexer_token(mgr->token);
		mgr->token = NULL;
	}
}
