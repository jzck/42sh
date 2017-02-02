/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_sep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:29:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/02 16:30:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_sep(t_list **alst, char *str)
{
	t_token		*token;

	if (*alst)
	{
		token = (*alst)->content;
		if (*token->data)
			return (lexer_sep(&(*alst)->next, str));
	}
	else
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	token = (*alst)->content;
	if (str[0] == '&')
		token->type = str[1] == '&' ? TK_AND_IF : TK_AMP;
	if (str[0] == '|')
		token->type = str[1] == '|' ? TK_OR_IF : TK_PIPE;
	token->type = (*str == ';') ? TK_SEMI : token->type;
	return (ft_tokenize(&(*alst)->next,
				str + 1 +
				(token->type & (TK_AND_IF | TK_OR_IF) ? 1 : 0),
				DEFAULT));
}
