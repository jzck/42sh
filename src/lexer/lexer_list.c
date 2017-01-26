/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:55:33 by ariard            #+#    #+#             */
/*   Updated: 2017/01/26 00:58:58 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_list(t_list **alst, char *str)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_LIST;
	while (*str)
	{
		if (ft_is_delim_list(*str))
		{
			while (ft_is_delim(*str) || *str == '\n')
				str++;
			if (ft_strncmp(str, "done", 4) == 0
				|| ft_strncmp(str, "do", 2) == 0)
				return (ft_tokenize(alst, str, DO_GROUP));
		}
		token_append(token, *str++);
	}
	return (0);
}
