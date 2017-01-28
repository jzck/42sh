/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:26:41 by ariard            #+#    #+#             */
/*   Updated: 2017/01/28 23:24:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_newline(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_list		*temp;
	
	DG("parsing newline");
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(list_ast, ast, start);
	*ast = NULL;
	ft_parse(&(*list_ast)->next, ast, &temp);
	return (0);
}
