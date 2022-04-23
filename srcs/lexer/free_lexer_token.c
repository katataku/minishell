/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takkatao <takkatao@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:48:05 by takkatao          #+#    #+#             */
/*   Updated: 2022/04/23 16:51:33 by takkatao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	free_lexer_token(t_token *token)
{
	int		index;

	index = 0;
	while (token->token[index] != T_NOTUSE)
	{
		free(token->word[index]);
		index++;
	}
	free(token->token);
	free(token->word);
	free(token);
}
