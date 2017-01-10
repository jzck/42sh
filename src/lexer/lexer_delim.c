/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:58:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 13:49:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_delim(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	while (ft_is_delim(*str))
		str++;
	if (*token->data)
		return (ft_tokenize(&(*alst)->next, str, DEFAULT));
	else
		return (ft_tokenize(alst, str, DEFAULT));
}
