/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:54:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 15:19:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_var(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	token->type = TK_N_WORD;
	str++;
	DG("check, *str=%c, data='%s'", *str, token->data);
	if (!ft_strchr(token->data, '$'))
		token_append(token, '$');
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
	token_append(token, *str);
	return (lexer_var(alst, str));
}
