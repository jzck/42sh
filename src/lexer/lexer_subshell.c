/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:35:38 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 22:09:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_subshell(t_list **alst, t_lexer *lexer)
{
	t_token	*token;
	t_list	**lst;

	lst = alst;
	if (*alst)
	{
		token = (*alst)->content;
		if (token->type)
			lst = &(*alst)->next;
	}
	token = token_init();
	*lst = ft_lstnew(token, sizeof(*token));
	token = (*lst)->content;
	if (lexer->str[lexer->pos] == '(')
		token->type = TK_PAREN_OPEN;
	else if (lexer->str[lexer->pos] == ')')
		token->type = TK_PAREN_CLOSE;
	token->data = lexer->str;
	lexer->pos++;
	return (lexer_lex(&(*lst)->next, lexer));
}
