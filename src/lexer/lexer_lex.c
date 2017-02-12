/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:08:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 22:58:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		(*g_lexer[])(t_list **alst, t_lexer *lexer) =
{
	&lexer_default,
	&lexer_newline,
	&lexer_delim,
	&lexer_sep,
	&lexer_word,
	&lexer_number,
	&lexer_great,
	&lexer_less,
	&lexer_greatand,
	&lexer_lessand,
	&lexer_quote,
	&lexer_dquote,
	&lexer_bquote,
	&lexer_bquote,
	&lexer_backslash,
	&lexer_paren,
	&lexer_comment,
	&lexer_end,
};

int		ft_is_delim(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		lexer_lex(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	if (lexer->str[lexer->pos] == 0)
		return (lexer_end(alst, lexer));
	if (!*alst)
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	return ((*g_lexer[lexer->state])(alst, lexer));
}
