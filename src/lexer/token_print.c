/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:39:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 12:50:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_print(t_list *lst)
{
	t_token		*token;
	int			i;
	t_type		type;

	while (lst)
	{
		i = 1;
		token = lst->content;
		type = token->type;
		while (type >> (i++ + 2))
			;
		ft_dprintf(2, "%02i '%s'\n", i, token->data);
		lst = lst->next;
	}
}
