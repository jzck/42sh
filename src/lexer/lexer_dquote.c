/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/10 00:33:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_dquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_DQ_WORD;
	if (*(int*)lexer->stack->content != DQUOTE)
		push(&lexer->stack, DQUOTE);
	lexer->pos++;
	if (lexer->str[lexer->pos] == '"')
	{
		lexer->pos++;
		lexer->state = WORD;
		pop(&lexer->stack);
		return (lexer_lex(alst, lexer));
	}
	else if (lexer->str[lexer->pos] == '\\')
	{
		if (lexer->str[lexer->pos + 1] == '"')
			token_append(token, lexer, 1, 0);
		else if (lexer->str[lexer->pos + 1] == 0)
		{
			push(&lexer->stack, BACKSLASH);
			return (0);
		}
		lexer->pos++;
		token_append(token, lexer, 1, 1);
		return (lexer_dquote(alst,lexer));
	}
	else if (lexer->str[lexer->pos] == '`')
		lexer_bquote(alst, lexer);
	else if (lexer->str[lexer->pos] == 0)
		return (0);
	token_append(token, lexer, 1, 0);
	return (lexer_dquote(alst, lexer));
}
