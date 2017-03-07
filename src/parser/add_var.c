/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:08:16 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 10:47:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		isvar(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type != TK_ASSIGNEMENT_WORD && token->type == TK_ASSIGNEMENT_WORD)
			return (1);
	}
	return (0);
}

int		add_var(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_btree		*new_node;

	if (!*ast)
		return (0);
	new_node = NULL;
	gen_node(&new_node);
	join_ast(ast, &new_node);
	node = (new_node)->item;
	node->type = TK_SEMI;
	add_cmd(&new_node, lst);
	return (0);
}
