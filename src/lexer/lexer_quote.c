/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/27 15:52:21 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_quote(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_Q_WORD;
	str++;
	if (*str == '\'')
		return (ft_tokenize(alst, str + 1, WORD));
	token_append(token, *str, 1);
	return (lexer_quote(alst, str));
}
