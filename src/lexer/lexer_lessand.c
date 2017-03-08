/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lessand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:58:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 12:12:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_lessand(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_LESSAND;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
/*	if (ft_isdigit(lexer->str[lexer->pos]))
	{
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	else if (lexer->str[lexer->pos] == '-')
	{
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
	lexer->state = DEFAULT;
	return (lexer_lex(alst, lexer));*/
}
