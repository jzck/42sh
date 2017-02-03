/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 00:55:33 by ariard            #+#    #+#             */
/*   Updated: 2017/02/03 15:12:49 by ariard           ###   ########.fr       */
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
			token_append(token, *str++, 0);
			while (ft_is_delim(*str) || *str == '\n')
				str++;
			if (ft_strncmp(str, "done", 4) == 0 && ft_isalpha(*(str + 4)) == 0) 
				return (ft_tokenize(alst, str, DONE));
			else if (ft_strncmp(str, "do", 2) == 0 && (ft_is_delim_list(*(str + 2))
				|| *(str + 2) == ' '))
				return (ft_tokenize(alst, str, DO));
			else if (ft_strncmp(str, "then", 4) == 0 && (ft_is_delim_list(*(str + 4))
				|| *(str + 4) == ' '))
				return (ft_tokenize(alst, str, THEN));
			else if (ft_strncmp(str, "fi", 2) == 0 && ft_isalpha(*(str + 2)) == 0) 
				return (ft_tokenize(alst, str, FI));
		}
		token_append(token, *str++, 0);
	}
	return (0);
}
