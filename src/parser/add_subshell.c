/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_subshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:41:50 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 15:34:12 by wescande         ###   ########.fr       */
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
		if (node->type == SUBSHELL && node->full == 0)
			return (1);
	}
	return (0);
}

int			add_subshell_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;

	DG("add subshell");
	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_PAREN_CLOSE && node->type == SUBSHELL)
		return ((node->full = 1));
	if (token->type == TK_RBRACE && node->type == TK_LBRACE)
		return ((node->full = 1));
	return (add_cmd(&(*ast)->right, lst));
}

int			add_subshell_sep(t_btree **ast, t_list **lst)
{
	return (add_sep(&(*ast)->right, lst));
}
