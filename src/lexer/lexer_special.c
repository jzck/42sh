/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_special.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:35:38 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 17:36:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_special(t_list **alst, char *str)
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
	if (*str == '(')
		token->type = TK_PAREN_OPEN;
	else if (*str == ')')
		token->type = TK_PAREN_CLOSE;
	else if (*str == '`')
		token->type = TK_BQUOTE;
	token->data = str;
	return (ft_tokenize(&(*lst)->next, str + 1, DEFAULT));
}
