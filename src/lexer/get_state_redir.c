/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 20:37:28 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 13:12:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexstate		get_state_redir(t_lexer *lexer)
{
	char	c;

	c = lexer->str[lexer->pos];
	if (c == '>')
		return (GREAT);
	else if (c == '<')
		return (LESS);
	return (0);
}
