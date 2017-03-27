/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 18:12:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 18:18:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_bang(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	token = (*alst)->content;
	if (token->type)
	{
		token->type = TK_BANG;
		lexer->state = DEFAULT;
		lexer->pos++;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	token->type = TK_WORD;
	lexer->state = WORD;
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
