#include "lexer.h"

bool	is_special_char(char c)
{
	return (c == ' ' || c == '\0' || c == '|' || c == ';'
		|| c == '>' || c == '<' || c == '\'' || c == '\"' || c == '`'
		|| c == '$' || c == '{' || c == '}');
}

bool	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}
