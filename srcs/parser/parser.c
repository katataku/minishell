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

	word_cnt = count_lst(token->word);
	exec_info = (t_exec_info *)calloc(1, sizeof(t_exec_info));
	exec_info->cmds = (char ***)calloc(1, sizeof(char **));
	exec_info->cmds[0] = (char **)calloc(word_cnt, sizeof(char *));
	i = 0;
	while (i < word_cnt)
	{
		exec_info->cmds[0][i] = token->word[i];
		i++;
	}
	exec_info->cmd_num = 1;
	exec_info->srcfile = NULL;
	exec_info->dstfile = NULL;
	exec_info->o_flag = 0;
	return (exec_info);
}
