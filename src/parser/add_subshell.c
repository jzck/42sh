/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:41:50 by ariard            #+#    #+#             */
/*   Updated: 2017/03/24 17:02:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			issubshell(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	(void)lst;
	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP || node->type == TK_PIPE
			|| node->type == TK_AND_IF || node->type == TK_OR_IF)
			&& issubshell(&(*ast)->right, lst) == 1)
			return (1);
		if (node->type == SUBSHELL && node->full == 0)
			return (1);
		if (node->type == TK_LBRACE && node->full == 0)
			return (1);
	}
	return (0);
}

int			add_subshell_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	token = (*lst)->content;
	node = (*ast)->item;
	if ((token->type == SUBSHELL && node->type == SUBSHELL)
	|| (token->type == TK_LBRACE && node->type == TK_LBRACE))
		node->nest++;
	if (((token->type == TK_PAREN_CLOSE && node->type == SUBSHELL)
	|| (token->type == TK_RBRACE && node->type == TK_LBRACE)) && node->nest > 0)
		node->nest--;
	if (token->type == TK_PAREN_CLOSE && node->type == SUBSHELL
	&& node->nest == 0)
		return ((node->full = 1));
	else if (token->type == TK_RBRACE && node->type == TK_LBRACE
	&& node->nest == 0)
		return ((node->full = 1));
	return (add_cmd(&(*ast)->right, lst));
}

int			add_subshell_sep(t_btree **ast, t_list **lst)
{
	return (add_sep(&(*ast)->right, lst));
}
