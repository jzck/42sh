/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:57:44 by ariard            #+#    #+#             */
/*   Updated: 2017/02/17 17:19:41 by ariard           ###   ########.fr       */
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
	}
	return (0);
}
