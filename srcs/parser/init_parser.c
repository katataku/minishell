/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:30:14 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 17:32:05 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	count_lst(int	*lst)
{
	int	count;

	count = 0;
	while (lst[count] != 0)
		count++;
	return (count);
}

static int	count_cmd_num(int	*lst)
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
