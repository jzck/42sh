/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 13:57:41 by jhalford         ###   ########.fr       */
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
		return (ft_tokenize(&(*alst)->next, str + 1, WORD));
	token_append(token, *str);
	return (lexer_quote(alst, str));
}
