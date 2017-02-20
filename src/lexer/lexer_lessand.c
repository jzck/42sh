/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lessand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:58:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 19:56:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_lessand(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_LESSAND;
	if (ft_isdigit(lexer->str[lexer->pos]))
	{
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		return (lexer_lessand(alst, lexer));
	}
	else if (lexer->str[lexer->pos] == '-')
	{
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	lexer->state = DEFAULT;
	return (lexer_lex(alst, lexer));
}
