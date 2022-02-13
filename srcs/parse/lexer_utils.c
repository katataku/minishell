#include "lexer.h"

bool	is_special_char(char c)
{
	return (c == ' ' || c == '\0' || c == '|' || c == ';'
		|| c == '>' || c == '<' || c == '\'' || c == '\"' || c == '`'
		|| c == '$' || c == '{' || c == '}');
}

void	set_token(	t_token	*t, int index, int token, char *word)
{
	t->token[index] = token;
	t->word[index] = ft_xstrdup(word);
}

void	set_state(t_lexer_manager *mgr, const char *str)
{
	if (*str == '\'')
		mgr->state = IN_SQUOTE;
	if (*str == '\"')
		mgr->state = IN_DQUOTE;
	if (*str == '`')
		mgr->state = IN_BQUOTE;
	if (*str == '{')
		mgr->state = IN_CBRACKET;
}
