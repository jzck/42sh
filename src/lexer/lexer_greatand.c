/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_greatand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:58 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/25 22:52:39 by ariard           ###   ########.fr       */
=======
/*   Updated: 2017/01/27 15:55:04 by wescande         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_greatand(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_GREATAND;
	if (ft_isdigit(*str))
	{
		token_append(token, *str, 0);
		return (lexer_greatand(alst, str + 1));
	}
	else if (*str == '-')
	{
		token_append(token, *str, 0);
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
	return (ft_tokenize(alst, str, DEFAULT));
}
