/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 20:42:13 by ariard            #+#    #+#             */
/*   Updated: 2017/03/22 15:30:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		iscase(t_btree **ast, t_list **lst)
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
			&& iscase(&(*ast)->right, lst) == 1)
			return (1);
		if ((node->type == TK_CASE || node->type == TK_PAREN_OPEN)
			&& node->pattern == 1 && node->full == 0)
			return (1);
	}
	return (0);
}

int		iscase_branch(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_PAREN_OPEN)
			&& node->nest == 0 && token->type == TK_PAREN_OPEN)
			return (1);
	}
	return (0);
}

int		add_case_cmd(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	if (token->type == TK_CASE && (node->type == TK_PAREN_OPEN
		|| node->type == TK_CASE))
		node->nest++;
	if (token->type == TK_ESAC && (node->type == TK_PAREN_OPEN
		|| node->type == TK_CASE) && node->nest > 0)
		return ((node->nest--));
	else if (token->type == TK_DSEMI && node->type == TK_PAREN_OPEN
		&& node->nest == 0)
		return ((node->full = 1));
	else if ((token->type == TK_ESAC)
		&& node->nest == 0)
		return ((node->full = 1));
	else if (token->type == TK_PAREN_CLOSE)
		return (0);
	return (add_cmd(&(*ast)->right, lst));
}
