/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:37:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 15:37:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		(*g_lexer[])(t_list **alst, char *str) =
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
	&lexer_backslash,
	&lexer_var,
	&lexer_special,
	&lexer_comment,
};

int		ft_is_delim(char c)
{
	return (c == ' ' || c == '\t');
}

int		ft_is_delim_list(char c)
{
	return (c == ';' || c == '\n' || c == '&');
}

int		ft_tokenize(t_list **alst, char *str, t_lexstate state)
{
	t_token	*token;

	if (!*str)
		return (0);
	if (!*alst)
	{
		token = token_init();
		*alst = ft_lstnew(token, sizeof(*token));
	}
	return ((*g_lexer[state])(alst, str));
}
