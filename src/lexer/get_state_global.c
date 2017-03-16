/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:39:06 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/17 00:08:12 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexstate		get_state_global(t_lexer *lexer)
{
	char	c;
	char	cn;
	char	cl;

	c = lexer->str[lexer->pos];
	cn = lexer->str[lexer->pos + 1];
	cl = lexer->str[lexer->pos ? lexer->pos - 1 : 0];
	if (ft_is_delim(c))
		return (DELIM);
	else if (c == '&' || c == ';' || c == '|' || c == '!')
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
	else if ((c == '{' && cn == ' ')
			|| (c == '}' && cl == ' '))
		return (CURLY_BRACKETS);
	else if (c == 0)
		return (END);
	return (0);
}
