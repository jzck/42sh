/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 21:42:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_default(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	char		c;

	c = lexer->str[lexer->pos];
	if ((lexer->state = get_state_global(lexer)))
	{
		DG("got state %i",lexer->state);
		return (lexer_lex(alst, lexer));
	}
	if ((lexer->state = get_state_redir(lexer)))
		return (lexer_lex(alst, lexer));
	DG("no special state, %c",lexer->str[lexer->pos]);
	lexer->state = ft_isdigit(c) ? NUMBER : WORD;
	token = (*alst)->content;
	token->type = TK_WORD;
	return (lexer_lex(alst, lexer));
}
