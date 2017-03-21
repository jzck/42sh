/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:49 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 13:42:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_backslash(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = token->type ? token->type : TK_WORD;
	lexer->pos++;
	lexer->state = WORD;
	if (lexer->str[lexer->pos] == 0)
	{
		if (!*token->data)
			ft_lst_delif(alst, token, &ft_addrcmp, &token_free);
		push(&lexer->stack, BACKSLASH);
		return (0);
	}
	token_append(token, lexer, 1, 1);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
