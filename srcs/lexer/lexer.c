/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:30:12 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/23 16:51:35 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	tokenize_special_char(t_lexer_manager *mgr, char *str)
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
	if (mgr->token->token[mgr->token_index - 1] == T_GTGT
		|| mgr->token->token[mgr->token_index - 1] == T_LTLT)
		return (1);
	return (0);
}

int	lexer_neutral(t_lexer_manager *mgr, char *str)
{
	char	*init_str;

	init_str = str;
	if (is_special_char(*str))
		return (tokenize_special_char(mgr, str) + 1);
	while (!is_special_char(*str))
	{
		set_state(mgr, str);
		mgr->word[mgr->word_index++] = *str++;
		if (mgr->state != NEUTRAL)
			return (str - init_str);
	}
	mgr->word[mgr->word_index] = '\0';
	set_token(mgr->token, mgr->token_index++, T_WORD, mgr->word);
	mgr->word_index = 0;
	return (str - init_str);
}

static void	lexer_not_neutral_postprocess(t_lexer_manager *mgr, char *str)
{
	if (is_special_char(*str))
	{
		mgr->word[mgr->word_index] = '\0';
		set_token(mgr->token, mgr->token_index++, T_WORD, mgr->word);
		mgr->word_index = 0;
	}
	mgr->state = NEUTRAL;
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
	else
		mgr->word[mgr->word_index++] = *str++;
	lexer_not_neutral_postprocess(mgr, str);
	return (str - init_str);
}

t_token	*lexer(char *str)
{
	t_lexer_manager	*mgr;
	t_token			*token;

	mgr = initialize_lexer(str);
	while (*str != '\0')
	{
		while ((*str == ' ' || *str == '\t') && mgr->state == NEUTRAL)
			str++;
		if (*str == '\0')
			break ;
		if (mgr->state == NEUTRAL)
			str += lexer_neutral(mgr, str);
		else
			str += lexer_not_neutral(mgr, str);
	}
	lexer_postprocess(mgr);
	token = mgr->token;
	free(mgr);
	return (token);
}
