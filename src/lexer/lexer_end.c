/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:58:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 13:16:57 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_end(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	if (lexer->str[lexer->pos] == '#')
		while (lexer->str[++lexer->pos])
			;
	if (*alst && (lexer->state == QUOTE
			|| lexer->state == DQUOTE
			|| lexer->state == BQUOTE))
	{
		token = (*alst)->content;
		ft_strappend(&lexer->str, (char[]){'\n', 0});
		token_append_char(token, '\n', 1, 0);
		lexer->pos++;
		return (0);
	}
	return (0);
}
