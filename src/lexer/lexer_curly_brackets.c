/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_curly_brackets.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 21:24:50 by ariard            #+#    #+#             */
/*   Updated: 2017/02/24 21:48:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			lexer_curly_brackets(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	t_list		**lst;

	DG("lexer curly brackets");
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
	if (lexer->str[lexer->pos] == '{')
	{
		DG("lbrace");
		token->type = TK_LBRACE;
		push(&lexer->stack, CURLY_BRACKETS);
	}
	else if (lexer->stack && *(int*)lexer->stack->content == CURLY_BRACKETS)
	{
		DG("rbrace");
		token->type = TK_RBRACE;
		pop(&lexer->stack);
	}
	lexer->pos++;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*lst)->next, lexer));
}
