/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_assignement_word.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 20:28:13 by ariard            #+#    #+#             */
/*   Updated: 2017/02/24 21:00:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lexer_assignement_word(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	char		c;

	token = (*alst)->content;
	if (token->type != TK_WORD && token->type != TK_ASSIGNEMENT_WORD)
	{
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		return (lexer_lex(alst, lexer));
	}
	token->type = TK_ASSIGNEMENT_WORD;
	token_append(token, lexer, 0, 0);
	lexer->pos++;
	c = lexer->str[lexer->pos];
	if ((lexer->state = get_state_global(lexer)))
		return (lexer_lex(alst, lexer));
	if ((lexer->state = get_state_redir(lexer)))
		return (lexer_lex(alst, lexer));
	lexer->state = ft_isdigit(c) ? NUMBER : ASSIGNEMENT_WORD;
	return(lexer_lex(alst, lexer));
}
