/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:09:06 by ahayashi          #+#    #+#             */
/*   Updated: 2022/04/23 14:16:27 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_status;

/*
 * ^Cは表示されてしまう
 */
void	sigint_handler(int signal)
{
	(void)signal;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_last_exit_status = STATUS_FAILURE;
}

void	set_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_token		*token;
	t_exec_info	*info;

	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		set_signal();
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		if (ft_strlen(line) >= MAX_WORD_SIZE)
		{
			if (ft_putendl_fd("line too long", STDERR_FILENO) == -1)
				return (EXIT_FAILURE);
			add_history(line);
			free(line);
			continue ;
		}
		token = lexer(line);
		if (token != NULL)
		{
			info = parser(token);
			if (info != NULL)
			{
				g_last_exit_status = execute(info);
				free_exec_info(info);
			}
			free_lexer_token(token);
		}
		add_history(line);
		free(line);
	}
	if (ft_putendl_fd("exit", STDERR_FILENO) == -1)
		return (EXIT_FAILURE);
	exit (g_last_exit_status);
}
