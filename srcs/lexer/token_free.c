/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/12 13:18:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_free(void *data, size_t size)
{
	t_token		*token;

	(void)size;
	token = data;
	if (!(token->type & TK_NON_FREEABLE))
		ft_strdel(&token->data);
	free(token);
}
