#ifndef LEXER_H
# define LEXER_H

# include "define.h"
# include "xlibft.h"

t_token			*lexer(const char *str);
t_lexer_manager	*initialize_lexer(char *str);
bool			is_special_char(char c);
void			set_token(	t_token	*t, int index, int token, char *word);
void			set_state(t_lexer_manager *mgr, const char *str);

#endif
