/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 23:25:47 by ariard            #+#    #+#             */
/*   Updated: 2017/02/03 15:12:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_if(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	if (ft_strncmp(str, "if", 2) == 0)
		token->type = TK_IF;
	else if (ft_isalnum(*str))
	{
		token_append(token, *str, 0);
		return (ft_tokenize(alst, str + 1, WORD));
	}
	return (ft_tokenize(&(*alst)->next, str + 3, LIST));
}
