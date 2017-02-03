/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:53 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/26 18:26:28 by ariard           ###   ########.fr       */
=======
/*   Updated: 2017/01/27 15:55:16 by wescande         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_less(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, str[0], 0);
	if (*(str + 1) == '&')
	{
		token->type = TK_LESSAND;
		token_append(token, str[1], 0);
		return (lexer_lessand(alst, str + 2));
	}
	else if (*(str + 1) == '<')
	{
		token->type = TK_DLESS;
		token_append(token, str[1], 0);
		return (ft_tokenize(&(*alst)->next, str + 2, DEFAULT));
	}
	else
	{
		token->type = TK_LESS;
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
}
