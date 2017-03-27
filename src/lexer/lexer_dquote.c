/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 18:52:15 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_dquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = token->type ? token->type : TK_WORD;
	if (lexer->str[lexer->pos] == '"')
	{
		if (get_lexer_stack(*lexer) == DQUOTE && (lexer->state = WORD))
			pop(&lexer->stack);
		else
			push(&lexer->stack, DQUOTE);
	}
	else if (lexer->str[lexer->pos] == '\\' && lexer->str[lexer->pos + 1] == 0)
	{
		lexer->pos++;
		if (lexer->str[lexer->pos] == 0)
			return (push(&lexer->stack, BACKSLASH) ? 0 : 0);
		token_append(token, lexer, 1, 0);
	}
	else if (lexer->str[lexer->pos] == '`' && (lexer->state = BQUOTE))
		return (lexer_lex(alst, lexer));
	else
		token_append(token, lexer, 1, 0);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
