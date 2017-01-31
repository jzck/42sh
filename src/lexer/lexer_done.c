/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_done.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:49:09 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 21:57:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_done(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;
	t_nest		*nest;

	nest = &data_singleton()->nest;
	if (*alst)
	{
		nest->do_group--;
		if (nest->do_group == 0)
			return (lexer_done(&(*alst)->next, str));	
		return (ft_tokenize(alst, str, LIST));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = TK_DONE;
	state = DEFAULT;
//	data_singleton()->scope |= (token->type == TK_DO) ? IN_LIST : OUT_LIST;
	return (ft_tokenize(&(*alst)->next, str + 4, state));
}
