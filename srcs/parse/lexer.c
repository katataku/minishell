#include "lexer.h"

bool	is_special_char(char c)
{
	return (c == ' ' || c == '\0' || c == '|' || c == ';'
		|| c == '>' || c == '<' || c == '\'' || c == '\"' || c == '`'
		|| c == '$' || c == '{' || c == '}');
}

void	tokenize_special_char(char *str, t_token *token, int *i, int *state)
{
	if (*str == '|')
		token->token[(*i)++] = T_BAR;
	if (*str == ';')
		token->token[(*i)++] = T_SEMI;
	if (*str == '>' && *(str + 1) == '>')
		token->token[(*i)++] = T_GTGT;
	if (*str == '>' && *(str + 1) != '>')
		token->token[(*i)++] = T_GT;
	if (*str == '<' && *(str + 1) == '<')
		token->token[(*i)++] = T_LTLT;
	if (*str == '<' && *(str + 1) != '<')
		token->token[(*i)++] = T_LT;
	if (*str == '\'')
	{
		token->token[(*i)++] = T_SQ;
		*state = IN_SQUOTE;
	}
	if (*str == '\"')
	{
		token->token[(*i)++] = T_DQ;
		*state = IN_DQUOTE;
	}
	if (*str == '`')
	{
		token->token[(*i)++] = T_BQ;
		*state = IN_BQUOTE;
	}
	if (*str == '$')
		token->token[(*i)++] = T_DOLLAR;
	if (*str == '{')
		token->token[(*i)++] = T_C_BRA_OPN;
	if (*str == '}')
		token->token[(*i)++] = T_C_BRA_CLS;
}

void	set_token(	t_token	*t, int index, int token, char *word)
{
	t->token[index] = token;
	t->word[index] = ft_xstrdup(word);
}

t_token	*lexer(const char *str)
{
	t_token	*token;
	int		token_index;
	int		word_index;
	char	word[4097];
	int		state;

	state = NEUTRAL;
	token = initialize_lexer(str);
	token_index = 0;
	word_index = 0;
	while (*str != '\0')
	{
		while (*str == ' ')
			*str++;
		if (is_special_char(*str) && state == NEUTRAL)
		{
			tokenize_special_char(str, token, &token_index, &state);
			if ((str[0] == '>' && str[1] == '>')
				|| (str[0] == '<' && str[1] == '<'))
				str++;
			str++;
		}
		else
		{
			if (state == NEUTRAL)
				while (!is_special_char(*str))
					word[word_index++] = *str++;
			if (state == IN_SQUOTE)
				while (!(*str == '\'' || *str == '\0'))
					word[word_index++] = *str++;
			if (state == IN_DQUOTE)
				while (!(*str == '\"' || *str == '\0'))
					word[word_index++] = *str++;
			if (state == IN_BQUOTE)
				while (!(*str == '`' || *str == '\0'))
					word[word_index++] = *str++;
			word[word_index] = '\0';
			set_token(token, token_index++, T_WORD, word);
			word_index = 0;
			state = NEUTRAL;
		}
	}
	return (token);
}
