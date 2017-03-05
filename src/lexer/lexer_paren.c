/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_paren.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:37:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 14:47:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_paren(t_list **alst, t_lexer *lexer)
{
	t_token	*token;
	t_list	**lst;

	lst = alst;
	if (*alst)
	{
		token = (*alst)->content;
		if (token->type)
			lst = &(*alst)->next;
	}
	token = token_init();
	*lst = ft_lstnew(token, sizeof(*token));
	token = (*lst)->content;
	if (lexer->str[lexer->pos] == '(')
	{
		token->type = TK_PAREN_OPEN;
		push(&lexer->stack, PAREN);
	}
	else if (lexer->stack && *(int*)lexer->stack->content == PAREN)
	{
		token->type = TK_PAREN_CLOSE;
		pop(&lexer->stack);
	}
	lexer->pos++;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*lst)->next, lexer));
}
