#ifndef LEXER_H
# define LEXER_H

# include "define.h"
# include "xlibft.h"

t_token	*tokenize(const char *str);
t_token	*initialize_t_token(char *str);
bool	is_special_char(char c);

#endif
