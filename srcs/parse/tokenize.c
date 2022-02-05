#include "minishell.h"
#include "typedefs.h"
#include "xlibft.h"

int	count_token_num(char *str)
{
	size_t	i;
	int		ans;

	i = 0;
	ans = 1;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			ans += 1;
		if (str[i] == '|')
			ans += 2;
		i++;
	}
	return (ans + 1);
}

t_token	*initialize_t_token(char *str)
{
	t_token	*ans;

	ans = (t_token *)ft_xcalloc(sizeof(t_token), 1);
	ans->token = (int *)ft_xcalloc(sizeof(int), count_token_num(str));
	ans->word = (char **)ft_xcalloc(sizeof(char *), count_token_num(str));
	return (ans);
}

bool	is_special_char(char c)
{
	if (c == ' ' || c == '|' || c == '\0')
		return (true);
	return (false);
}

t_token	*tokenize(const char *str)
{
	t_token	*ans;
	int		i;
	int		j;
	char	word[4097];

	ans = initialize_t_token(str);
	i = 0;
	while (*str != '\0')
	{
		if (*str == '|')
			ans->token[i++] = T_BAR;
		if (is_special_char(*str))
		{
			str++;
			continue ;
		}
		j = 0;
		while (!is_special_char(*str))
			word[j++] = *str++;
		word[j] = '\0';
		ans->token[i] = T_WORD;
		ans->word[i++] = ft_xstrdup(word);
	}
	return (ans);
}
