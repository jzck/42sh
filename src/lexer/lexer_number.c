/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/22 17:40:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_number(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	if ((state = get_lexer_state(str)))
		return (ft_tokenize(alst, str, state));
	if (*str == '>')
		return (ft_tokenize(alst, str, GREAT));
	else if (*str == '<')
		return (ft_tokenize(alst, str, LESS));
	else if (ft_isdigit(*str))
	{
		token_append(token, *str);
		return (lexer_number(alst, str + 1));
	}
	return (ft_tokenize(alst, str, DEFAULT));
}
