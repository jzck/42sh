/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:18:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/26 18:32:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

#define TOKEN_INCR	10

int		token_append(t_token *token, char c)
{
	if ((int)ft_strlen(token->data) >= token->size)
	{
		token->data = (char *)ft_realloc(token->data, token->size + TOKEN_INCR);
		token->size += TOKEN_INCR - 1;
	}
	ft_strcat(token->data, (char[]){c, 0});
	return (0);
}
