/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/20 20:52:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_dquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (lexer->str[lexer->pos] == '"')
	{
		lexer->pos++;
		if (!(lexer->stack && *(int*)lexer->stack->content == DQUOTE))
		{
			push(&lexer->stack, DQUOTE);
			return (lexer_lex(alst, lexer));
		}
		lexer->state = WORD;
		pop(&lexer->stack);
		return (lexer_lex(alst, lexer));
	}
	if (lexer->str[lexer->pos] == '\\')
	{
		lexer->pos++;
		if (lexer->str[lexer->pos] == 0)
			return (0);
		else
			token_append(token, lexer, 1, 1);
		lexer->pos++;
		return (lexer_lex(alst,lexer));
	}
	else if (lexer->str[lexer->pos] == '`')
	{
		lexer->state = DQUOTE_BQUOTE;
		return (lexer_bquote(alst, lexer));
	}
	token_append(token, lexer, 1, 0);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
