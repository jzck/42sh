/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_curly_braces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:29:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 16:29:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			lexer_curly_braces(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	token = (*alst)->content;
	if (token->type)
		lexer_lex(&(*alst)->next, lexer);
	if (lexer->str[lexer->pos] == '{')
	{
		token->type = TK_LBRACE;
		push(&lexer->stack, PAREN);
	}
	else if (get_lexer_stack(*lexer))
	{
		token->type = TK_RBRACE;
		pop(&lexer->stack);
	}
	lexer->pos++;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
