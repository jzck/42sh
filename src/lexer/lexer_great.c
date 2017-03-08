/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:35 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 12:10:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_great(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	/* if (token->type) */
	/* 	return (lexer_lex(&(*alst)->next, lexer)); */
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
