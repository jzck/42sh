/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 22:13:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_quote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_Q_WORD;
	lexer->pos++;
	push(&lexer->stack, QUOTE);
	if (lexer->str[lexer->pos] == '\'')
	{
		lexer->state = WORD;
		lexer->pos++;
		pop(&lexer->stack);
		return (lexer_lex(alst, lexer));
	}
	else if (lexer->str[lexer->pos] == 0)
		return (0);
	token_append(token, lexer, 1, 1);
	return (lexer_quote(alst, lexer));
}
