#include "parser.h"

int	count_lst(int	*lst)
{
	int	count;

	count = 0;
	while (lst[count] != NULL)
		count++;
	return (count);
}

int	count_cmd_num(int	*lst)
{
	int	i;
	int	count;

	count = 1;
	i = 0;
	while (lst[i] != 0)
	{
		if (lst[i] == T_BAR)
			count++;
		i++;
	}
	return (count);
}

t_exec_info	*parser(t_token *token)
{
	t_exec_info	*exec_info;
	int			word_cnt;
	int			idx_token;
	int			idx_cmd;
	int			idx_word;

	word_cnt = count_lst(token->token);
	exec_info = (t_exec_info *)ft_xcalloc(1, sizeof(t_exec_info));
	exec_info->cmd_num = count_cmd_num(token->token);
	exec_info->cmds = (char ***)ft_xcalloc(exec_info->cmd_num, sizeof(char **));
	idx_token = 0;
	idx_word = 0;
	idx_cmd = 0;
	exec_info->cmds[idx_cmd] = (char **)ft_xcalloc(word_cnt, sizeof(char *));
	while (token->token[idx_token] != NULL)
	{
		if (token->token[idx_token] == T_WORD)
			exec_info->cmds[idx_cmd][idx_word++] = token->word[idx_token];
		if (token->token[idx_token] == T_LT)
			exec_info->srcfile = token->word[++idx_token];
		if (token->token[idx_token] == T_GTGT)
			exec_info->o_flag = O_APPEND;
		if (token->token[idx_token] == T_GT
			|| token->token[idx_token] == T_GTGT)
			exec_info->dstfile = token->word[++idx_token];
		if (token->token[idx_token] == T_BAR)
		{
			exec_info->cmds[++idx_cmd] = (char **)ft_xcalloc(word_cnt, sizeof(char *));
			idx_word = 0;
		}
		idx_token++;
	}
	return (exec_info);
}
