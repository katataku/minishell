#include "minishell.h"
#include "typedefs.h"
#include "xlibft.h"

int	count_token_num(char *str)
{
	size_t	i;
	int		token_num;

	i = 0;
	token_num = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			token_num += 1;
		if (str[i] == '|')
			token_num += 2;
		i++;
	}
	return (token_num + 1);
}

t_token	*initialize_t_token(char *str)
{
	t_token	*token;

	token = (t_token *)ft_xcalloc(sizeof(t_token), 1);
	token->token = (int *)ft_xcalloc(sizeof(int), count_token_num(str));
	token->word = (char **)ft_xcalloc(sizeof(char *), count_token_num(str));
	return (token);
}

bool	is_special_char(char c)
{
	return (c == ' ' || c == '\0' || c == '|');
}

void	tokenize_special_char(char *str, t_token *token, int *i)
{
	if (*str == '|')
		token->token[(*i)++] = T_BAR;
}

t_token	*tokenize(const char *str)
{
	t_token	*token;
	int		i;
	int		j;
	char	word[4097];

	token = initialize_t_token(str);
	i = 0;
	while (*str != '\0')
	{
		tokenize_special_char(str, token, &i);
		if (is_special_char(*str))
		{
			str++;
			continue ;
		}
		j = 0;
		while (!is_special_char(*str))
			word[j++] = *str++;
		word[j] = '\0';
		token->token[i] = T_WORD;
		token->word[i++] = ft_xstrdup(word);
	}
	return (token);
}
