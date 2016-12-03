/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_greatand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 11:57:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_greatand(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_GREATAND;
	if (ft_isdigit(*str))
	{
		token_append(token, *str);
		return (lexer_greatand(alst, str + 1));
	}
	else if (*str == '-')
	{
		token_append(token, *str);
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
	return (ft_tokenize(alst, str, DEFAULT));
}
