#include "lexer.h"

int	g_last_exit_status;

void	tokenize_special_char(t_lexer_manager *mgr, char *str)
{
	if (*str == '|')
		mgr->token->token[mgr->token_index++] = T_BAR;
	if (*str == ';')
		mgr->token->token[mgr->token_index++] = T_SEMI;
	if (*str == '>' && *(str + 1) == '>')
		mgr->token->token[mgr->token_index++] = T_GTGT;
	if (*str == '>' && *(str + 1) != '>')
		mgr->token->token[mgr->token_index++] = T_GT;
	if (*str == '<' && *(str + 1) == '<')
		mgr->token->token[mgr->token_index++] = T_LTLT;
	if (*str == '<' && *(str + 1) != '<')
		mgr->token->token[mgr->token_index++] = T_LT;
	if (*str == '\'')
		mgr->token->token[mgr->token_index++] = T_SQ;
	if (*str == '\"')
		mgr->token->token[mgr->token_index++] = T_DQ;
	if (*str == '`')
		mgr->token->token[mgr->token_index++] = T_BQ;
	if (*str == '$')
		mgr->token->token[mgr->token_index++] = T_DOLLAR;
	if (*str == '{')
		mgr->token->token[mgr->token_index++] = T_C_BRA_OPN;
	if (*str == '}')
		mgr->token->token[mgr->token_index++] = T_C_BRA_CLS;
}

int	lexer_neutral(t_lexer_manager *mgr, char *str)
{
	char	*init_str;

	init_str = str;
	if (is_special_char(*str))
	{
		set_state(mgr, str);
		tokenize_special_char(mgr, str);
		if (mgr->token->token[mgr->token_index - 1] == T_GTGT
			|| mgr->token->token[mgr->token_index - 1] == T_LTLT)
			str++;
		str++;
	}
	else
	{
		while (!is_special_char(*str))
			mgr->word[mgr->word_index++] = *str++;
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
	mgr->word[mgr->word_index] = '\0';
	if (*str == '\0')
		g_last_exit_status = ERR_CODE_MISUSE_BUILTIN;
	set_token(mgr->token, mgr->token_index++, T_WORD, mgr->word);
	mgr->state = NEUTRAL;
	return (str - init_str);
}

t_token	*lexer(char *str)
{
	t_lexer_manager	*mgr;

	mgr = initialize_lexer(str);
	while (*str != '\0')
	{
		mgr->word_index = 0;
		while (*str == ' ')
			str++;
		if (mgr->state == NEUTRAL)
			str += lexer_neutral(mgr, str);
		else
			str += lexer_not_neutral(mgr, str);
	}
	return (mgr->token);
}
