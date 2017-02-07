/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 13:39:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_free(void *data, size_t size)
{
	t_token		*token;

	(void)size;
	token = data;
	if (!(token->type & TK_NON_FREEABLE))
	{
		ft_strdel(&token->data);
		ft_memdel((void **)&token->esc);
		ft_memdel((void **)&token->esc2);
	}
	free(token);
}
