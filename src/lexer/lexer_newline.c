/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:19:46 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 19:55:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_newline(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	if (*alst)
	{
		token = (*alst)->content;
		if (*token->data)
			return (lexer_newline(&(*alst)->next, lexer));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = TK_NEWLINE;
	return (lexer_lex(&(*alst)->next, lexer));
}
