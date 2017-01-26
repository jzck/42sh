/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_do_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:48:48 by ariard            #+#    #+#             */
/*   Updated: 2017/01/26 00:59:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_do_group(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;
	int			type;

	type = (str[0] == 'd' && str[1] == 'o' && str[2] != 'n' ?
		2 : 4);
	if (*alst)
	{
		if (ft_is_delim_list(*(str + type)) || *(str + type) == ' ')
			return (lexer_do_group(&(*alst)->next, str));
		return (ft_tokenize(alst, str + 1, LIST));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	token->type = (type == 2 ? TK_DO : TK_DONE);
	state = (token->type == TK_DO) ? LIST : DEFAULT;	
	return (ft_tokenize(&(*alst)->next, str + 1, state));
}
