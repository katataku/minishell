/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:09:06 by ahayashi          #+#    #+#             */
/*   Updated: 2022/03/20 10:35:45 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
}

/*
 * SIGQUITは特に何もしなくても無視されていそう　
 */
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
		line = readline("> ");
		if (line == NULL)
			break ;
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		token = lexer(line);
		if (token != NULL)
		{
			info = parser(token);
			g_last_exit_status = execute(info);
			free_lexer_token(token);
			free_exec_info(info);
		}
		add_history(line);
		free(line);
	}
	if (ft_putendl_fd("exit", STDERR_FILENO) == -1)
		return (EXIT_FAILURE);
	exit (g_last_exit_status);
}
