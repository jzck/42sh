/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:30:25 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 17:05:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_token		*token_init(void)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->type = 0;
	token->size = 8;
	token->data = ft_strnew(token->size + 1);
	token->esc = (unsigned char *)ft_strnew(token->size / 8 + 1);
	token->expand_data = NULL;
	return (token);
}
