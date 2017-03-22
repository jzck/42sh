/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:08:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 18:13:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		(*g_lexer[])(t_list **alst, t_lexer *lexer) =
{
	&lexer_default,
	&lexer_paren,
	&lexer_heredoc,
	&lexer_newline,
	&lexer_delim,
	&lexer_sep,
	&lexer_word,
	&lexer_number,
	&lexer_less,
	&lexer_great,
	&lexer_quote,
	&lexer_dquote,
	&lexer_bquote,
	&lexer_backslash,
	&lexer_curly_braces,
	&lexer_end,
};

int		ft_is_delim(char c)
{
	return (c == ' ' || c == '\t');
}

int		lexer_lex(t_list **alst, t_lexer *lexer)
{
	t_token	*token;

	if (lexer->str[lexer->pos] == 0
		|| (lexer->str[lexer->pos] == '#'
			&& lexer->state != QUOTE
			&& lexer->state != DQUOTE))
		return (lexer_end(alst, lexer));
	if (!*alst)
	{
		if (!(token = token_init())
			|| !(*alst = ft_lstnew(token, sizeof(*token))))
			return (-1);
		if (token)
			free(token);
	}
	return ((*g_lexer[lexer->state])(alst, lexer));
}
