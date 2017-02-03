/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:35 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/24 19:06:00 by ariard           ###   ########.fr       */
=======
/*   Updated: 2017/01/27 15:54:53 by wescande         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_great(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, str[0], 0);
	if (*(str + 1) == '&')
	{
		token->type = TK_GREATAND;
		token_append(token, str[1], 0);
		return (lexer_greatand(alst, str + 2));
	}
	else if (*(str + 1) == '>')
	{
		token->type = TK_DGREAT;
		token_append(token, str[1], 0);
		return (ft_tokenize(&(*alst)->next, str + 2, DEFAULT));
	}
	else
	{
		token->type = TK_GREAT;
		return (ft_tokenize(&(*alst)->next, str + 1, DEFAULT));
	}
}
