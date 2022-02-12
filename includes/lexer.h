#ifndef LEXER_H
# define LEXER_H

# include "define.h"
# include "xlibft.h"

t_token			*lexer(const char *str);
t_lexer_manager	*initialize_lexer(char *str);
bool			is_special_char(char c);
bool			is_space(char c);

#endif
