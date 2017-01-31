/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_then.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:29:49 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 23:59:37 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_then(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;
	
	if (*alst)
		return (lexer_then(&(*alst)->next, str));
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = TK_THEN;
	state = LIST;
	return (ft_tokenize(&(*alst)->next, str + 4, state));
}		
