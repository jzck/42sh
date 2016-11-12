/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:30:25 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 17:47:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token		*token_init()
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->type = 0;
	token->size = 10;
	token->data = ft_strnew(token->size);
	return (token);
}
