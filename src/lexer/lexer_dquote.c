/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:58 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/25 22:52:47 by ariard           ###   ########.fr       */
=======
/*   Updated: 2017/01/27 15:53:31 by wescande         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_dquote(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_DQ_WORD;
	str++;
	if (*str == '\"')
		return (ft_tokenize(alst, str + 1, DEFAULT));
	if (*str == '\\')
	{
		token_append(token, *(str + 1), 1);
		return (lexer_dquote(alst, str + 1));
	}
	token_append(token, *str, 1);
	return (lexer_dquote(alst, str));
}
