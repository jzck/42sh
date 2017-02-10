/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:03:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 22:07:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_bquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (lexer->str[lexer->pos] == '`')
	{
		lexer->pos++;
		if (!(lexer->stack && *(int*)lexer->stack->content == BQUOTE))
		{
			push(&lexer->stack, BQUOTE);
			return (lexer_lex(alst, lexer));
		}
		lexer->state = WORD;
		pop(&lexer->stack);
		return (lexer_lex(alst, lexer));
	}
	token_append(token, lexer, 0, 0);
	lexer->pos++;
	return (lexer_quote(alst, lexer));
}

