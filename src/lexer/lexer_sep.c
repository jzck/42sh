/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:29:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 19:40:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_sep(t_list **alst, t_lexer *lexer)
{
	t_token	*token;
	char	c;
	char	cn;

	lexer->state = DEFAULT;
	if (*alst)
	{
		token = (*alst)->content;
		if (*token->data)
			return (lexer_sep(&(*alst)->next, lexer));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	c = lexer->str[lexer->pos];
	cn = lexer->str[lexer->pos + 1];
	if (c == '&')
		token->type = cn == '&' ? TK_AND_IF : TK_AMP;
	else if (c == '|')
		token->type = cn == '|' ? TK_OR_IF : TK_PIPE;
	else if (c == '!')
		token->type = TK_BANG;
	token->type = (c == ';') ? TK_SEMI : token->type;
	token->type = (c == ';') && (cn == ';') ? TK_DSEMI : token->type;
// c est ici que ca bug, ca marche plus les bitwise sur des enums
	lexer->pos += 1 + (token->type & (TK_AND_IF | TK_OR_IF | TK_DSEMI) ? 1 : 0);
	return (lexer_lex(&(*alst)->next, lexer));
}
