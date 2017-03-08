/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:03:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 23:32:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_bquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	int			top_state;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (lexer->state == DQUOTE_BQUOTE)
		token_append(token, lexer, 1, 0);
	else
		token_append(token, lexer, 0, 0);
	if (lexer->str[lexer->pos] == '`')
	{
		lexer->pos++;
		if (!(lexer->stack && (*(int*)lexer->stack->content == BQUOTE
							|| *(int*)lexer->stack->content == DQUOTE_BQUOTE)))
		{
			push(&lexer->stack, lexer->state);
			return (lexer_lex(alst, lexer));
		}
		top_state = pop(&lexer->stack);
		lexer->state = top_state == DQUOTE_BQUOTE ? DQUOTE : DEFAULT;
		return (lexer_lex(alst, lexer));
	}
	if (lexer->str[lexer->pos] == '\\')
	{
		lexer->pos++;
		if (lexer->str[lexer->pos] == 0)
		{
			push(&lexer->stack, BACKSLASH);
			return (0);
		}
		else
			token_append(token, lexer, 1, 1);
		lexer->pos++;
		return (lexer_lex(alst,lexer));
	}
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
