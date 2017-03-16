/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 22:59:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_dquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (lexer->str[lexer->pos] == '"')
	{
		if (get_lexer_stack(*lexer) == DQUOTE && (lexer->state = WORD))
			pop(&lexer->stack);
		else
			push(&lexer->stack, DQUOTE);
	}
	else if (lexer->str[lexer->pos] == '\\')
	{
		if (lexer->str[lexer->pos + 1] == 0)
			return(lexer_backslash(alst, lexer));
		token_append(token, lexer, 1, 1);
	}
	else if (lexer->str[lexer->pos] == '`' && (lexer->state = BQUOTE))
		return (lexer_lex(alst, lexer));
	else
		token_append(token, lexer, 1, 0);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
