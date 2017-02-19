/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 22:17:14 by ariard            #+#    #+#             */
/*   Updated: 2017/02/18 20:12:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		isloop(t_btree **ast)
{
	t_astnode	*node;

	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		DG("TEST LOOP");
		if (node->type == TK_WHILE && node->full == 1)
		{
			DG("DON ENTER");
			return (2);
		}
		if (node->type == TK_WHILE && node->full == 0)
		{
			DG(" NOFULL");
			return (1);
		}
	}
	return (0);
}

int		add_loop_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	DG("add loop cmd");
	if (token->type == TK_WHILE && node->type == TK_WHILE)
	{
		DG("nest one more");
		node->nest++;
	}
	if (token->type == TK_DONE && node->type == TK_WHILE && node->nest > 0)
	{
		node->nest--;
		DG("nest one less");
	}
	else if (token->type == TK_DONE && node->type == TK_WHILE
		&& node->nest == 0)
	{
		DG("WHILE FULL");
		return ((node->full = 1));
	}
	if (token->type == TK_DO)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right && isloop(&(*ast)->left) != 2)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}

int		add_loop_sep(t_btree **ast, t_list **lst)
{
	if (!(*ast)->right)
		return (add_sep(&(*ast)->left, lst));
	else
		return (add_sep(&(*ast)->right, lst));
	return (0);
}
