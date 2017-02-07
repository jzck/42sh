/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 12:15:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 12:56:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_comment(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	if (*str == '\n')
		return (ft_tokenize(&(*alst)->next, str, NEWLINE));
	return (lexer_comment(alst, str + 1));
}
