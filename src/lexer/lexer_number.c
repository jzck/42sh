/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:06:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_number(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
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
