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
#include <readline/readline.h>

int	main(int argc, char **argv, char **env)
{
	char *line = NULL;
	(void)argc;
	(void)argv;
	(void)env;

    while (1)
    {
        line = readline("> ");
        if (line == NULL || ft_strlen(line) == 0)
        {
            free(line);
			break;
        }
        printf("line is '%s'\n", line);
        free(line);
    }
}
