/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:39:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 20:37:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_print(t_list *lst)
{
	t_token		*token;

	while (lst)
	{
		DG("in token print");
		if (lst->content)
			token = lst->content;
		if (token->type)
			DG("token : %s data [%s]", read_state(token->type), token->data);
		lst = lst->next;
	}
}
