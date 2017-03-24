/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 22:03:48 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 17:02:40 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_bquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	int			back;

	token = (*alst)->content;
	token->type = token->type ? token->type : TK_WORD;
	back = 0;
	if (lexer->str[lexer->pos] == '`')
	{
		if (get_lexer_stack(*lexer) != BQUOTE)
			push(&lexer->stack, lexer->state);
		else
			lexer->state = pop(&lexer->stack) &&
				get_lexer_stack(*lexer) == DQUOTE ? DQUOTE : DEFAULT;
	}
	else if (lexer->str[lexer->pos] == '\\' && (back = 1))
	{
		lexer->pos++;
		if (lexer->str[lexer->pos] == 0)
			return (push(&lexer->stack, BACKSLASH) ? 0 : 0);
	}
	token_append(token, lexer, back || token->type == TK_ASSIGNMENT_WORD
		|| get_lexer_stack2(*lexer) == DQUOTE, back);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
