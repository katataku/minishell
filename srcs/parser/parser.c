#include "parser.h"

int	count_lst(char **lst)
{
	int	count;

	count = 0;
	while (lst[count] != NULL)
		count++;
	return (count);
}

t_exec_info	*parser(t_token *token)
{
	t_exec_info	*exec_info;
	int			word_cnt;
	int			i;

	word_cnt = count_lst(token->token);
	exec_info = (t_exec_info *)ft_xcalloc(1, sizeof(t_exec_info));
	exec_info->cmds = (char ***)ft_xcalloc(1, sizeof(char **));
	exec_info->cmds[0] = (char **)ft_xcalloc(word_cnt, sizeof(char *));
	i = 0;
	while (token->token[i] != NULL)
	{
		if (token->token[i] == T_WORD)
			exec_info->cmds[0][i] = token->word[i];
		if (token->token[i] == T_LT)
			exec_info->srcfile = token->word[++i];
		if (token->token[i] == T_GTGT)
			exec_info->o_flag = O_APPEND;
		if (token->token[i] == T_GT || token->token[i] == T_GTGT)
			exec_info->dstfile = token->word[++i];
		i++;
	}
	exec_info->cmd_num = 1;
	return (exec_info);
}
