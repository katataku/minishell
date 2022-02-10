#include "lexer.h"

int	count_token_num(char *str)
{
	size_t	i;
	int		token_num;

	i = 0;
	token_num = 1;
	while (str[i] != '\0')
	{
		if (is_special_char(str[i]))
			token_num += 2;
		if (str[i] == ' ')
			token_num -= 1;
		if (str[i] == '>' && str[i + 1] == '>')
			i++;
		if (str[i] == '<' && str[i + 1] == '<')
			i++;
		i++;
	}
	return (token_num + 1);
}

t_token	*initialize_lexer(char *str)
{
	t_token	*token;

	token = (t_token *)ft_xcalloc(1, sizeof(t_token));
	token->token = (int *)ft_xcalloc(count_token_num(str), sizeof(int));
	token->word = (char **)ft_xcalloc(count_token_num(str), sizeof(char *));
	return (token);
}
