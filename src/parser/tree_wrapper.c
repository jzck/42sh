/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_wrapper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:57:44 by ariard            #+#    #+#             */
/*   Updated: 2017/03/24 15:00:14 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ft_bzero((void *)&((t_astnode *)(*ast)->item)->data, sizeof(t_astdata));
		((t_astnode *)(*ast)->item)->nest = 0;
		((t_astnode *)(*ast)->item)->full = 0;
		((t_astnode *)(*ast)->item)->cache = 0;
		((t_astnode *)(*ast)->item)->type = TK_NEWLINE;
		((t_astnode *)(*ast)->item)->pattern = 0;
	}
	return (0);
}

int			isnull(t_btree **ast, t_list **lst)
{
	(void)ast;
	(void)lst;
	return (-1);
}

int			add_null(t_btree **ast, t_list **lst)
{
	(void)ast;
	(void)lst;
	return (-1);
}

int			add_branch(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_btree		*new_node;

	new_node = NULL;
	gen_node(&new_node);
	join_ast(ast, &new_node);
	node = (new_node)->item;
	node->type = TK_NEWLINE;
	return (add_cmd(ast, lst));
}
