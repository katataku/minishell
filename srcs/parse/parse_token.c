#include "minishell.h"
#include "typedefs.h"
#include "xlibft.h"

t_token	*parse_token(const char *str)
{
	t_token	*ans;
	int		i;
	char	**strs;

	ans = (t_token *)ft_xcalloc(sizeof(t_token), 1);
	strs = ft_split(str, ' ');
	i = 0;
	while (strs[i] != NULL)
		i++;
	ans->token = (int *)ft_xcalloc(sizeof(int), i + 1);
	ans->word = (char **)ft_xcalloc(sizeof(char *), i + 1);
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
