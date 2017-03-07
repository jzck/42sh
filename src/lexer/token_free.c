/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:57:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_free(void *data, size_t size)
{
	t_token		*token;

	(void)size;
	token = data;
	ft_strdel(&token->data);
	ft_memdel((void **)&token->esc);
	ft_memdel((void **)&token->esc2);
	free(token);
}
