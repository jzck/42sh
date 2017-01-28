/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:18:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/27 21:54:32 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		token_append(t_token *token, char c, short int esc)
{
	int		len;

	len = ft_strlen(token->data);
	if (len >= token->size)
	{
		token->size += 8;
		token->data = (char *)ft_realloc(token->data, token->size + 1);
		token->esc = (unsigned char *)ft_realloc((char *)token->esc, token->size / 8 + 1);
		token->esc[token->size / 8 - 1] = 0; 
	}
	ft_strcat(token->data, (char[2]){c, '\0'});
	if (esc)
		token->esc[len / 8] |= 1 << (7 - len % 8);
	return (0);
}
