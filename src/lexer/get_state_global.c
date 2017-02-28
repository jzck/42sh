/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:39:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/24 21:39:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexstate		get_state_global(t_lexer *lexer)
{
	char	c;

	c = lexer->str[lexer->pos];
	if (ft_is_delim(c))
		return (DELIM);
	else if (c == '#')
		return (COMMENT);
	else if (c == '&' || c == ';' || c == '|')
		return (SEP);
	else if (c == '\\')
		return (BACKSLASH);
	else if (c == '\'')
		return (QUOTE);
	else if (c == '\"')
		return (DQUOTE);
	else if (c == '`')
		return (BQUOTE);
	else if (c == '(' || c == ')')
		return (PAREN);
	else if (c == '{' || c == '}')
		return (CURLY_BRACKETS);
	else if (c == '=')
		return (ASSIGNEMENT_WORD);
	else if (c == 0)
		return (END);
	return (0);
}
