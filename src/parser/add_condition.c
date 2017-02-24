/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_condition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:12:52 by ariard            #+#    #+#             */
/*   Updated: 2017/02/24 14:51:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		iscondition(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_CASE || node->type == TK_PAREN_OPEN)
			&& node->pattern = 0 && token->type == TK_WORD)
			return (2);
		if (node->type == TK_CASE)
			return (3);
		if (node->type == TK_PAREN_OPEN && nest == 0)
			return (3);
		if (node->type == TK_PAREN_OPEN && nest > 0)
			return (0);	
	}
	return (0);
}

int			add_condition_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_IF && (node->type == TK_IF || node->type == TK_ELIF
		|| node->type == TK_ELSE))
		node->nest++;
	if (token->type == TK_FI && (node->type == TK_IF || node->type == TK_ELIF
		|| node->type == TK_ELSE) && node->nest > 0)
		node->nest--;
	else if (token->type == TK_FI && (node->type == TK_IF || node->type == TK_ELIF
		|| node->type == TK_ELSE)) 
		return ((node->full = 1));
	if (token->type == TK_THEN)
		return (add_cmd(&(*ast)->right, lst));
	else if (!(*ast)->right)
		return (add_cmd(&(*ast)->left, lst));
	else
		return (add_cmd(&(*ast)->right, lst));
	return (0);
}	

int			add_condition_sep(t_btree **ast, t_list **lst)
{
	if (!(*ast)->right)
		return (add_sep(&(*ast)->left, lst));
	else
		return (add_sep(&(*ast)->right, lst));
	return (0);
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
