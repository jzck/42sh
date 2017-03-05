/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_greatand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 18:23:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_greatand(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_GREATAND;
/*	if (ft_isdigit(lexer->str[lexer->pos]))
	{
//		token_append(token, lexer, 0, 0);
//		lexer->pos++;
//		DG();
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	else if (lexer->str[lexer->pos] == '-')
	{
//		token_append(token, lexer, 0, 0);
//		lexer->pos++;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}*/
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
	//return (lexer_lex(alst, lexer));
}
