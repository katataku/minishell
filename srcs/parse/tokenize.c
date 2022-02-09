#include "minishell.h"
#include "typedefs.h"
#include "xlibft.h"

bool	is_special_char(char c)
{
	return (c == ' ' || c == '\0' || c == '|' || c == ';'
		|| c == '>' || c == '<' || c == '\'' || c == '\"'
		|| c == '$');
}

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

t_token	*initialize_t_token(char *str)
{
	t_token	*token;

	token = (t_token *)ft_xcalloc(1, sizeof(t_token));
	token->token = (int *)ft_xcalloc(count_token_num(str), sizeof(int));
	token->word = (char **)ft_xcalloc(count_token_num(str), sizeof(char *));
	return (token);
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
		token->token[(*i)++] = T_BQ;
	if (*str == '$')
		token->token[(*i)++] = T_DOLLER;
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
			if ((str[0] == '>' && str[1] == '>')
				|| (str[0] == '<' && str[1] == '<'))
				str++;
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
