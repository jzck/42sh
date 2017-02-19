/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:57:44 by ariard            #+#    #+#             */
/*   Updated: 2017/02/19 16:34:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			join_ast(t_btree **ast, t_btree **new_node)
{
	(*new_node)->left = *ast; 
	*ast = *new_node;	
	return (0);
}

int			gen_node(t_btree **ast)
{
	t_astnode	item;

	if (!*ast)
	{
		*ast = btree_create_node(&item, sizeof(item));
		((t_astnode *)(*ast)->item)->data.token = NULL;
		((t_astnode *)(*ast)->item)->data.redir.word.word = NULL;
		((t_astnode *)(*ast)->item)->nest = 0;
		((t_astnode *)(*ast)->item)->full = 0;
		((t_astnode *)(*ast)->item)->type = 0;
	}
	return (0);
}
