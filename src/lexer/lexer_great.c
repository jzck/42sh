/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 18:20:02 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_great(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, lexer, 0, 0);
	lexer->pos++;
	if (lexer->str[lexer->pos] == '&')
	{
		DG("lex greatand");	
		token->type = TK_GREATAND;
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		return (lexer_greatand(alst, lexer));
	}
	if (lexer->str[lexer->pos] == '>')
	{
		DG("lex great");
		token->type = TK_DGREAT;
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	token->type = TK_GREAT;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
