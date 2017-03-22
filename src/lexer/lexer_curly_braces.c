/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_curly_braces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:29:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 18:15:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			lexer_curly_braces(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	token = (*alst)->content;
	if (token->type)
		lexer_lex(&(*alst)->next, lexer);
	if (lexer->str[lexer->pos] == '{')
	{
		token->type = TK_LBRACE;
		push(&lexer->stack, CURLY_BRACKETS);
	}
	else
	{
		token->type = TK_RBRACE;
		if (get_lexer_stack(*lexer) == CURLY_BRACKETS)
			pop(&lexer->stack);
	}
	lexer->pos++;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
