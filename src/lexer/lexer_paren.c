/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:37:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 17:16:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_paren(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	token = (*alst)->content;
	if (token->type)
		return (lexer_lex(&(*alst)->next, lexer));
	if (lexer->str[lexer->pos] == '(')
	{
		token->type = TK_PAREN_OPEN;
		push(&lexer->stack, PAREN);
	}
	else
	{
		token->type = TK_PAREN_CLOSE;
		if (get_lexer_stack(*lexer) == PAREN)
			pop(&lexer->stack);
	}
	lexer->pos++;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
