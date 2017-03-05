/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:58:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 17:29:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_end(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	if ((*alst && (lexer->state == QUOTE || lexer->state == DQUOTE
			|| lexer->state == BQUOTE)) || get_lexer_stack(*lexer) == DLESS)
	{
		ft_strappend(&lexer->str, (char[]){'\n', 0});
		lexer->pos++;
		if (get_lexer_stack(*lexer) == DLESS)
		{
			token = (*(t_list**)lexer->heredoc_stack->content)->content;
			token_append_char(token, '\n', 0, 0);
		}
		else
		{
			token = (*alst)->content;
			token_append_char(token, '\n', 1, 0);
		}
		return (0);
	}
	return (0);
}
