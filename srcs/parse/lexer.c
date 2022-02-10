#include "lexer.h"

bool	is_special_char(char c)
{
	return (c == ' ' || c == '\0' || c == '|' || c == ';'
		|| c == '>' || c == '<' || c == '\'' || c == '\"' || c == '`'
		|| c == '$' || c == '{' || c == '}');
}

void	tokenize_special_char(char *str, t_token *token, int *i)
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
		token->token[(*i)++] = T_SQ;
	if (*str == '\"')
		token->token[(*i)++] = T_DQ;
	if (*str == '`')
		token->token[(*i)++] = T_BQ;
	if (*str == '$')
		token->token[(*i)++] = T_DOLLER;
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

	token = initialize_lexer(str);
	token_index = 0;
	while (*str != '\0')
	{
		tokenize_special_char(str, token, &token_index);
		if (is_special_char(*str))
		{
			if ((str[0] == '>' && str[1] == '>')
				|| (str[0] == '<' && str[1] == '<'))
				str++;
			str++;
			continue ;
		}
		word_index = 0;
		while (!is_special_char(*str))
			word[word_index++] = *str++;
		word[word_index] = '\0';
		set_token(token, token_index++, T_WORD, word);
	}
	return (token);
}
