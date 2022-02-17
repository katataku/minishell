/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahayashi <ahayashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:09:06 by ahayashi          #+#    #+#             */
/*   Updated: 2022/02/16 16:09:06 by ahayashi         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * ^Cは表示されてしまう
 */
void	sigint_handler(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	rl_replace_line("", 0);
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
	char	*line;

	(void)argc;
	(void)argv;
	(void)env;
	set_signal();
	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			break ;
		if (*line == '\0')
		{
			free(line);
			continue ;
		}
		printf("line is '%s'\n", line);
		add_history(line);
		free(line);
	}
}
