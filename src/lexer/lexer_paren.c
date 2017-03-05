/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:37:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 16:29:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_paren(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	token = (*alst)->content;
	if (token->type)
		lexer_lex(&(*alst)->next, lexer);
	if (lexer->str[lexer->pos] == '(')
	{
		token->type = TK_PAREN_OPEN;
		push(&lexer->stack, PAREN);
	}
	else if (get_lexer_stack(*lexer))
	{
		token->type = TK_PAREN_CLOSE;
		pop(&lexer->stack);
	}
	lexer->pos++;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
