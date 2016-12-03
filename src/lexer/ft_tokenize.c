/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:37:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:50:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		(*g_lexer[])(t_list **alst, char *str) =
{
	&lexer_default,
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
};

int		ft_is_delim(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int		ft_tokenize(t_list **alst, char *str, t_lexstate state)
{
	t_token	*token;

	if (!*str)
		return (0);
	token = token_init();
	if (!*alst)
		*alst = ft_lstnew(token, sizeof(*token));
	if (ft_is_delim(*str))
		state = DELIM;
	else if (*str == '&' || *str == ';' || *str == '|')
		state = SEP;
	else if (*str == '\\')
		state = BACKSLASH;
	else if (*str == '\'')
		return ((*g_lexer[QUOTE])(alst, str + 1));
	else if (*str == '\"')
		return ((*g_lexer[DQUOTE])(alst, str + 1));
	return ((*g_lexer[state])(alst, str));
}
