#include "parser.h"

t_exec_info	*parser(t_token *token)
{
	t_exec_info	*exec_info;

	exec_info = (t_exec_info *)calloc(1, sizeof(t_exec_info));
	exec_info->cmds = (char ***)calloc(2, sizeof(char **));
	exec_info->cmds[0] = (char **)calloc(3,sizeof(char *));
	for (int i = 0; i < 2; i++)
	{
		exec_info->cmds[0][i] = token->word[i];
	}
	exec_info->cmd_num = 1;
	exec_info->srcfile = NULL;
	exec_info->dstfile = NULL;
	exec_info->o_flag = 0;
	return (exec_info);
}
