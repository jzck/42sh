/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:39:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 18:39:53 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_print(t_list *lst)
{
	t_token		*token;

	while (lst)
	{
		if (lst->content)
		{
			token = lst->content;
			DG("token : %s data [%s]", read_state(token->type), token->data);
		}
		lst = lst->next;
	}
}
