/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:58:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 20:02:45 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_delim(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	while (ft_is_delim(lexer->str[lexer->pos]))
		lexer->pos++;
	lexer->state = DEFAULT;
	if (token->type)
	{
		return (lexer_lex(&(*alst)->next, lexer));
	}
	else
	{
		if (lexer->str[lexer->pos] == 0)
			ft_lst_delif(alst, (*alst)->content, &ft_addrcmp, &token_free);
		return (lexer_lex(alst, lexer));
	}
}
