/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:03:28 by ariard            #+#    #+#             */
/*   Updated: 2017/01/30 19:52:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parse_while(t_list **list_ast, t_btree **ast,
		t_list **start, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_WHILE;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(list_ast, &(*ast)->left, start);
	ft_parse(list_ast, &(*ast)->right, start);
 	return (0);
}
