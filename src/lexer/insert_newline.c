/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 21:05:23 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 21:12:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			insert_newline(t_list **alst)
{
	t_token	*token;

	DG("insert newline");
	token = token_init();
	token->type = TK_NEWLINE;
	ft_lsteadd(alst, ft_lstnew(token, sizeof(*token)));
	return (0);
}	
