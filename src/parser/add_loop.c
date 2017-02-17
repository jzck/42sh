/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:17:14 by ariard            #+#    #+#             */
/*   Updated: 2017/02/17 23:38:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		isloop(t_btree **ast)
{
	t_astnode	*node;

	node = NULL;
	if (*ast)
	{
		DG("end isloop");
		node = (*ast)->item;
		if (node->data.loop == 1)
			return (2);
		if (node->type == TK_WHILE)
			return (1);
	}
	return (0);
}

int		add_loop_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	DG("add loop cmd");
	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_DONE)
		return ((node->data.loop = 1));
	else if (token->type == TK_DO)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right && isloop(&(*ast)->left) != 2)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}

int		add_loop_sep(t_btree **ast, t_list **lst)
{
	DG("add loop sep");
	if (!(*ast)->right)
		return (add_sep(&(*ast)->left, lst));
	else
		return (add_sep(&(*ast)->right, lst));
	return (0);
}
