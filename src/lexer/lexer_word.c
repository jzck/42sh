/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/01 23:32:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_word(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	token->type = TK_WORD;
	if ((state = get_state_global(lexer)))
	{
		lexer->state = state;
		return (lexer_lex(alst, lexer));
	}
	if ((state = get_state_redir(lexer)))
	{
		lexer->state = state;
		return (lexer_lex(alst, lexer));
	}
	token_append(token, lexer, 0, 0);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
