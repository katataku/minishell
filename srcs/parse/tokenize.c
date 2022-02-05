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

t_token	*tokenize(const char *str)
{
	t_token	*ans;
	int		i;
	char	**strs;

	ans = (t_token *)ft_xcalloc(sizeof(t_token), 1);
	ans->token = (int *)ft_xcalloc(sizeof(int), count_token_num(str));
	ans->word = (char **)ft_xcalloc(sizeof(char *), count_token_num(str));
	strs = ft_split(str, ' ');
	i = 0;
	while (strs[i] != NULL)
	{
		if (ft_strncmp(strs[i], "|", strlen(strs[i])) == 0)
			ans->token[i] = T_BAR;
		else
		{
			ans->token[i] = T_WORD;
			ans->word[i] = ft_xstrdup(strs[i]);
		}
		i++;
	}
	return (ans);
}
