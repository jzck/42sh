/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:43:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_dquote(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	if (*str == '\"')
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	if (*str == '\\')
	{
		token_append(token, *(str + 1));
		return (lexer_dquote(alst, str + 2));
	}
	token_append(token, *str);
	return (lexer_dquote(alst, str + 1));
}
