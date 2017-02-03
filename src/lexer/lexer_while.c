/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:58:12 by ariard            #+#    #+#             */
/*   Updated: 2017/02/03 15:14:06 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_while(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	if (ft_strncmp(str, "while", 5) == 0)
		token->type = TK_WHILE;
	else if (ft_isalnum(*str))
	{
		token_append(token, *str, 0);
		return (ft_tokenize(alst, str + 1, WORD));
	}
	return (ft_tokenize(&(*alst)->next, str + 6, LIST));
}
