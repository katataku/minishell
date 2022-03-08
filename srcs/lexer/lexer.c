/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:30:12 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/08 16:03:57 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	g_last_exit_status;

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
		g_last_exit_status = STATUS_MISUSE_BUILTIN;
	if (*str != '\0')
		mgr->word[mgr->word_index++] = *str++;
	mgr->word[mgr->word_index] = '\0';
	set_token(mgr->token, mgr->token_index++, T_WORD, mgr->word);
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
	while (*str != '\0')
	{
		if (mgr->state == NEUTRAL)
			mgr->word_index = 0;
		while (*str == ' ')
			str++;
		if (mgr->state == NEUTRAL)
			str += lexer_neutral(mgr, str);
		else
			str += lexer_not_neutral(mgr, str);
	}
	if (g_last_exit_status != 0)
	{
		free_lexer_token(mgr->token);
		mgr->token = NULL;
	}
	token = mgr->token;
	free(mgr);
	return (token);
}
