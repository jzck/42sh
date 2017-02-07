/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:54:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 11:36:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

/*
int		lexer_var(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	token->type = TK_N_WORD;
	str++;
	if (!ft_strchr(token->data, '$'))
		token_append(token, '$', 0);
	if (!*str)
	{
		token_expand_var(token);
		return (0);
	}
	if ((state = get_lexer_state(str)))
	{
		token_expand_var(token);
		return (ft_tokenize(alst, str, state));
	}
	token_append(token, *str, 0);
	return (lexer_var(alst, str));
}*/
