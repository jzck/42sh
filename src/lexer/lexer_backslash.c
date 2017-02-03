/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_backslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:49 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/23 23:24:40 by ariard           ###   ########.fr       */
=======
/*   Updated: 2017/01/30 13:07:52 by wescande         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_backslash(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_WORD;
	token_append(token, str[1], 1);
	return (ft_tokenize(alst, str + 2, WORD));
}
