/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_fi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:35:08 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 23:59:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_fi(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;

	if (*alst)
		return (lexer_fi(&(*alst)->next, str));
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = TK_FI;
	state = DEFAULT;
	return (ft_tokenize(&(*alst)->next, str + 2, state));
}
