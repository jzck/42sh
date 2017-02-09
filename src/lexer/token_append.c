/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:18:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 17:00:41 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		token_append(t_token *token, char c, short int esc, short int esc2)
{
	int		len;

	len = ft_strlen(token->data);
	if (len >= token->size)
	{
		token->size += 8;
		token->data = (char *)ft_realloc(token->data, token->size + 1);
		token->esc = (unsigned char *)ft_memrealloc(token->esc,
												(token->size >> 3),
												(token->size >> 3) + 1);
		token->esc[token->size >> 3] = 0; 
		token->esc2 = (unsigned char *)ft_memrealloc(token->esc2,
												(token->size >> 3),
												(token->size >> 3) + 1);
		token->esc2[token->size >> 3] = 0; 
	}
	ft_strcat(token->data, (char[2]){c, '\0'});
	token->esc[len >> 3] |= esc << (7 - len % 8);
	token->esc2[len >> 3] |= esc2 << (7 - len % 8);
	return (0);
}
