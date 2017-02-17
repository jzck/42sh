/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:07 by ariard            #+#    #+#             */
/*   Updated: 2017/02/17 23:34:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			add_sep(t_btree **ast, t_list **lst)
{	
	t_token		*token;
	t_astnode	*node;
	t_btree		*new_node;
	
	DG("add sep");
	if (isloop(&(*ast)->right) == 1 || isloop(ast))
		return (add_loop_sep(ast, lst));
	new_node = NULL;
	gen_node(&new_node);
	join_ast(ast, &new_node);
	token = (*lst)->content;
	node = (new_node)->item;
	node->type = token->type;
	return (0);
}
