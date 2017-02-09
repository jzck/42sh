/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 20:40:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_default(t_list **alst, t_lexer *lexer)
{
	t_lexstate	state;
	t_token		*token;
	char		c;

	c = lexer->str[lexer->pos];
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
	else if (ft_isdigit(c))
		lexer->state = NUMBER;
	else
		lexer->state = WORD;
	token = (*alst)->content;
	token_append(token, lexer, 0, 0);
	token->type = TK_N_WORD;
	return (lexer_lex(alst, lexer));
}
