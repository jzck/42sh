/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_delim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:58:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/26 16:30:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_delim(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	while (ft_is_delim(*str))
		str++;
	if (token->type)
		return (ft_tokenize(&(*alst)->next, str, DEFAULT));
	else
		return (ft_tokenize(alst, str, DEFAULT));
}
