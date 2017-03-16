/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:30:25 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 19:07:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token		*token_init(void)
{
	t_token	*token;

	if (!(token = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	token->type = 0;
	token->size = 8;
	token->data = ft_strnew(token->size + 1);
	token->esc = (unsigned char *)ft_strnew((token->size >> 3));
	token->esc2 = (unsigned char *)ft_strnew((token->size >> 3));
	return (token);
}
