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

/*
* 初期化処理
* メモリ確保は多めに取っている。
*/
void	init_parser(t_exec_info **e, t_token *t, int *i, int *j)
{
	int	index;
	int	word_cnt;

	word_cnt = count_lst(t->token);
	*e = (t_exec_info *)ft_xcalloc(1, sizeof(t_exec_info));
	(*e)->cmd_num = count_cmd_num(t->token);
	(*e)->cmds = (char ***)ft_xcalloc((*e)->cmd_num, sizeof(char **));
	index = 0;
	while (index < (*e)->cmd_num)
		(*e)->cmds[index++] = (char **)ft_xcalloc(word_cnt, sizeof(char *));
	*i = -1;
	*j = 0;
}

t_exec_info	*parser(t_token *token)
{
	t_exec_info	*exec_info;
	int			idx_token;
	int			idx_cmd;
	int			idx_word;

	init_parser(&exec_info, token, &idx_token, &idx_cmd);
	idx_word = 0;
	while (token->token[++idx_token] != 0)
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
			idx_cmd++;
			idx_word = 0;
		}
	}
	return (exec_info);
}
