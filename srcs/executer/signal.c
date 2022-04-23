/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:28:18 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/23 17:28:18 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

/*
 * ^Cは表示されてしまう
 * heredoc実行中は、改行表示後にexitすることでmainループに戻る
 */
static void	sigint_handler_heredoc(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', 1);
	exit(1);
	return ;
}

/*
 * SIGQUITは特に何もしなくても無視されていそう
 */
void	set_signal_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sigint_handler_heredoc);
}

static void	nop_handler(int signal)
{
	(void)signal;
}

void	set_signal_parent(void)
{
	signal(SIGQUIT, nop_handler);
	signal(SIGINT, nop_handler);
}
