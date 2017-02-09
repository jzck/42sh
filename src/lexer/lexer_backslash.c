/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:49 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 19:53:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_backslash(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	lexer->pos++;
	token_append(token, lexer, 1, 1);
	lexer->pos++;
	lexer->state = WORD;
	return (lexer_lex(alst, lexer));
}
