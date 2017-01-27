/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:39:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/27 16:08:16 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_print(t_list *lst)
{
	t_token		*token;
	int			i;
	t_type		type;
	int			index;

	while (lst)
	{
		i = -1;
		token = lst->content;
		type = token->type;
		while (type >> (i++ + 2))
			;
		DG("%02i '%s'", i, token->data);
		index = -1;
		while (++index < token->size / 8)
			ft_dprintf(3, "|%b vs %x vs %c| ", token->esc[index], token->esc[index], token->esc[index]);
		ft_dprintf(3, "\n");
		lst = lst->next;
	}
}
