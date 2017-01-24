/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:19:46 by ariard            #+#    #+#             */
/*   Updated: 2017/01/24 01:25:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_newline(t_list **alst, char *str)
{
	t_token		*token;

	if (*alst)
	{
		token = (*alst)->content;
		if (*token->data)
			return (lexer_newline(&(*alst)->next, str));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = TK_NEWLINE;
	return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
}
