/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:39:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 12:08:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_print(t_list *lst)
{
	t_token		*token;

	while (lst)
	{
		token = lst->content;
		ft_dprintf(2, "%#010llx: '%s'\n", token->type, token->data);
		lst = lst->next;
	}
}
