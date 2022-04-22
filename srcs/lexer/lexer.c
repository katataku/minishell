/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:30:12 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/19 16:03:33 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	tokenize_special_char(t_lexer_manager *mgr, char *str)
{
	if (*str == '|')
		mgr->token->token[mgr->token_index++] = T_BAR;
	if (*str == '>' && *(str + 1) == '>')
		mgr->token->token[mgr->token_index++] = T_GTGT;
	if (*str == '>' && *(str + 1) != '>')
		mgr->token->token[mgr->token_index++] = T_GT;
	if (*str == '<' && *(str + 1) == '<')
		mgr->token->token[mgr->token_index++] = T_LTLT;
	if (*str == '<' && *(str + 1) != '<')
		mgr->token->token[mgr->token_index++] = T_LT;
}

int	lexer_neutral(t_lexer_manager *mgr, char *str)
{
	char	*init_str;

	init_str = str;
	if (is_special_char(*str))
	{
		tokenize_special_char(mgr, str);
		if (mgr->token->token[mgr->token_index - 1] == T_GTGT
			|| mgr->token->token[mgr->token_index - 1] == T_LTLT)
			str++;
		str++;
	}
	else
	{
		while (!is_special_char(*str))
		{
			set_state(mgr, str);
			mgr->word[mgr->word_index++] = *str++;
			if (mgr->state != NEUTRAL)
			{
				return (str - init_str);
			}
		}
		mgr->word[mgr->word_index] = '\0';
		set_token(mgr->token, mgr->token_index++, T_WORD, mgr->word);
		mgr->word_index = 0;
	}
	return (str - init_str);
}

int	lexer_not_neutral(t_lexer_manager *mgr, char *str)
{
	char	*init_str;

	init_str = str;
	if (mgr->state == IN_SQUOTE)
		while (!(*str == '\'' || *str == '\0'))
			mgr->word[mgr->word_index++] = *str++;
	if (mgr->state == IN_DQUOTE)
		while (!(*str == '\"' || *str == '\0'))
			mgr->word[mgr->word_index++] = *str++;
	if (mgr->state == IN_BQUOTE)
		while (!(*str == '`' || *str == '\0'))
			mgr->word[mgr->word_index++] = *str++;
	if (mgr->state == IN_CBRACKET)
		while (!(*str == '}' || *str == '\0'))
			mgr->word[mgr->word_index++] = *str++;
	if (*str == '\0')
		mgr->is_misuse_builtin = true;
	if (*str != '\0')
		mgr->word[mgr->word_index++] = *str++;
	if (is_special_char(*str))
	{
		mgr->word[mgr->word_index] = '\0';
		set_token(mgr->token, mgr->token_index++, T_WORD, mgr->word);
		mgr->word_index = 0;
	}
	mgr->state = NEUTRAL;
	return (str - init_str);
}

void	free_lexer_token(t_token *token)
{
	int		index;

	index = 0;
	while (token->token[index] != T_NOTUSE)
	{
		free(token->word[index]);
		index++;
	}
	free(token->token);
	free(token->word);
	free(token);
}

t_token	*lexer(char *str)
{
	t_lexer_manager	*mgr;
	t_token			*token;

	mgr = initialize_lexer(str);
	mgr->word_index = 0;
	while (*str != '\0')
	{
		while (*str == ' ' && mgr->state == NEUTRAL)
			str++;
		if (*str == '\0')
			break ;
		if (mgr->state == NEUTRAL)
			str += lexer_neutral(mgr, str);
		else
			str += lexer_not_neutral(mgr, str);
	}
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
	token = mgr->token;
	free(mgr);
	return (token);
}
