/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:37:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/30 16:57:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer		*g_lexer[] =
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
	if (*str == '&' || *str == ';' || *str == '|')
		state = SEP;
	else if (*str == '\'')
	{
		state = QUOTE;
		str++;
	}
	else if (*str == '\"')
	{
		state = DQUOTE;
		str++;
	}
	else if (*str == '\\')
		state = BACKSLASH;
	return ((*g_lexer[state])(alst, str));
}
