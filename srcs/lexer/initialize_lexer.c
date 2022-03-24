#include "lexer.h"

/*
* token個数としてありうる最大値を返す関数。
* tokne個数と厳密には一致していないこともある。
*/
int	max_token_num(char *str)
{
	size_t	i;
	int		token_num;

	i = 0;
	token_num = 1;
	while (str[i] != '\0')
	{
		if (is_special_char(str[i]))
			token_num += 2;
		i++;
	}
	return (token_num);
}

t_lexer_manager	*initialize_lexer(char *str)
{
	t_token			*token;
	t_lexer_manager	*mgr;

	token = (t_token *)ft_xcalloc(1, sizeof(t_token));
	token->token = (int *)ft_xcalloc(max_token_num(str) + 1, sizeof(int));
	token->word = (char **)ft_xcalloc(max_token_num(str) + 1, sizeof(char *));
	mgr = (t_lexer_manager *)ft_xcalloc(1, sizeof(t_lexer_manager));
	mgr->state = NEUTRAL;
	mgr->token = token;
	mgr->token_index = 0;
	mgr->word_index = 0;
	mgr->is_misuse_builtin = false;
	return (mgr);
}
