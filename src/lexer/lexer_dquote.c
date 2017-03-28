/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/28 15:46:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_dquote(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = token->type ? token->type : TK_WORD;
	if (lexer->str[lexer->pos] == '"')
		get_lexer_stack(*lexer) == DQUOTE && (lexer->state = WORD) ?
			pop(&lexer->stack) : push(&lexer->stack, DQUOTE) && 0;
	else if (lexer->str[lexer->pos] == '\\')
	{
		if (lexer->str[++lexer->pos] == 0)
			return (push(&lexer->stack, BACKSLASH) ? 0 : 0);
		else if (lexer->str[lexer->pos] == '"')
			token_append(token, lexer, 1, 1);
		else
			--lexer->pos;
	}
	else if (lexer->str[lexer->pos] == '`' && (lexer->state = BQUOTE))
		return (lexer_lex(alst, lexer));
	else
		token_append(token, lexer, 1, 0);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
