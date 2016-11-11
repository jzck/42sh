/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:18:42 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 17:47:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

int		token_append(t_token *token, char str)
{
	if (ft_strlen(token->data) <= token->size)
	{
		token->data = (char *)ft_realloc(token->size + 10);
		token->size += 10;
	}
	ft_strcat(token->data, &str);
}
