/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:38:46 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/23 17:32:46 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_exec_info(t_exec_info *exec_info)
{
	int		i;
	char	**cur_cmd;

	i = 0;
	while (i < exec_info->cmd_num)
	{
		cur_cmd = exec_info->cmds[i];
		while (*cur_cmd != NULL)
		{
			free(*cur_cmd);
			cur_cmd++;
		}
		free(exec_info->cmds[i]);
		i++;
	}
	free(exec_info->cmds);
	free(exec_info->srcfile);
	free(exec_info->heredoc_word);
	free(exec_info->dstfile);
	free(exec_info);
}

t_exec_info	*syntaxerror(t_exec_info	*exec_info)
{
	g_last_exit_status = STATUS_MISUSE_BUILTIN;
	puterr("minishell", "syntax error");
	free_exec_info(exec_info);
	return (NULL);
}

t_exec_info	*parser_legt(t_exec_info *exec_info, t_token *token, int *ti)
{
	if (token->token[*ti] == T_LT)
	{
		exec_info->heredoc_word = NULL;
		if (token->word[++(*ti)] == NULL)
			return (syntaxerror(exec_info));
		exec_info->srcfile = ft_xstrdup(token->word[*ti]);
	}
	if (token->token[*ti] == T_LTLT)
	{
		exec_info->srcfile = NULL;
		if (token->word[++(*ti)] == NULL)
			return (syntaxerror(exec_info));
		exec_info->heredoc_word = ft_xstrdup(token->word[*ti]);
	}
	if (token->token[*ti] == T_GTGT)
		exec_info->o_flag |= O_APPEND;
	if (token->token[*ti] == T_GT || token->token[*ti] == T_GTGT)
	{
		if (token->word[++(*ti)] == NULL)
			return (syntaxerror(exec_info));
		exec_info->dstfile = ft_xstrdup(token->word[*ti]);
	}
	return (exec_info);
}

t_exec_info	*parser(t_token *token)
{
	t_exec_info	*exec_info;
	int			ti;
	int			ci;
	int			wi;
	int			i;

	init_parser(&exec_info, token, &ti, &ci);
	wi = 0;
	while (token->token[++ti] != 0)
	{
		if (token->token[ti] == T_WORD)
			exec_info->cmds[ci][wi++] = ft_xstrdup(token->word[ti]);
		if (token->token[ti] == T_BAR)
		{
			ci++;
			wi = 0;
		}
		if (parser_legt(exec_info, token, &ti) == NULL)
			return (NULL);
	}
	i = 0;
	while (i < exec_info->cmd_num)
		if (exec_info->cmds[i++][0] == NULL)
			return (syntaxerror(exec_info));
	return (exec_info);
}
