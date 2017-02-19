/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:12:52 by ariard            #+#    #+#             */
/*   Updated: 2017/02/19 18:46:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		iscondition(t_btree **ast)
{
	t_astnode	*node;

	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP) && iscondition(&(*ast)->right) == 1)
			return (1);
		if ((node->type == TK_IF || node->type == TK_ELIF)
			&& node->full == 1)
			return (2);
		if ((node->type == TK_IF || node->type == TK_ELIF)
			&& node->full == 0)
			return (1);
	}
	return (0);
}

int		add_condition_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_IF && node->type == TK_IF)
		node->nest++;
	if (token->type == TK_FI && node->type == TK_IF && node->nest > 0)
		node->nest--;
	else if (token->type == TK_FI && node->type == TK_IF && node->nest == 0)
		return ((node->full = 1));
	if (token->type == TK_THEN)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right && iscondition(&(*ast)->left) != 2)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}
