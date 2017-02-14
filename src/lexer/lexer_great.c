/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 19:57:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_great(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, lexer, 0, 0);
	if (lexer->str[lexer->pos + 1] == '&')
	{
		token->type = TK_GREATAND;
		lexer->pos++;
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		return (lexer_greatand(alst, lexer));
	}
	if (lexer->str[lexer->pos + 1] == '>')
	{
		token->type = TK_DGREAT;
		lexer->pos++;
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	else
	{
		token->type = TK_GREAT;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
}
