#include "parser.h"

int	count_lst(int	*lst)
{
	int	count;

	count = 0;
	while (lst[count] != 0)
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
* コマンドをNULL終端にするためにword_cntに + 1している。
*/
void	init_parser(t_exec_info **e, t_token *t, int *i, int *j)
{
	int	index;
	int	word_cnt;

	word_cnt = count_lst(t->token) + 1;
	*e = (t_exec_info *)ft_xcalloc(1, sizeof(t_exec_info));
	(*e)->cmd_num = count_cmd_num(t->token);
	(*e)->o_flag = O_WRONLY | O_CREAT;
	(*e)->cmds = (char ***)ft_xcalloc((*e)->cmd_num, sizeof(char **));
	index = 0;
	while (index < (*e)->cmd_num)
		(*e)->cmds[index++] = (char **)ft_xcalloc(word_cnt, sizeof(char *));
	*i = -1;
	*j = 0;
}

void	free_exec_info(t_exec_info *exec_info)
{
	int		i;
	char	**cur_cmd;

	i = 0;
	while (i < exec_info->cmd_num)
	{
		cur_cmd = exec_info->cmds[i];
		while (*cur_cmd != NULL)
		{
			free(*cur_cmd);
			cur_cmd++;
		}
		free(exec_info->cmds[i]);
		i++;
	}
	free(exec_info->cmds);
	free(exec_info->srcfile);
	free(exec_info->heredoc_word);
	free(exec_info->dstfile);
	free(exec_info);
}

t_exec_info	*parser(t_token *token)
{
	t_exec_info	*exec_info;
	int			ti;
	int			ci;
	int			wi;

	init_parser(&exec_info, token, &ti, &ci);
	wi = 0;
	while (token->token[++ti] != 0)
	{
		if (token->token[ti] == T_WORD)
			exec_info->cmds[ci][wi++] = token->word[ti];
		if (token->token[ti] == T_LT)
		{
			exec_info->heredoc_word = NULL;
			exec_info->srcfile = token->word[++ti];
		}
		if (token->token[ti] == T_LTLT)
		{
			exec_info->srcfile = NULL;
			exec_info->heredoc_word = token->word[++ti];
		}
		if (token->token[ti] == T_GTGT)
			exec_info->o_flag |= O_APPEND;
		if (token->token[ti] == T_GT || token->token[ti] == T_GTGT)
			exec_info->dstfile = token->word[++ti];
		if (token->token[ti] == T_BAR)
		{
			ci++;
			wi = 0;
		}
	}
	return (exec_info);
}
