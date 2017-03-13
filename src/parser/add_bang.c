/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bang.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:57:45 by ariard            #+#    #+#             */
/*   Updated: 2017/03/13 19:32:08 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isbang(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	(void)lst;
	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP) && isbang(&(*ast)->right, lst) == 1)
			return (1);
		if (node->type == TK_BANG && node->full == 0)
			return (1);
	}
	return (0);
}

int		isbang_sep(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if ((token->type == TK_SEMI || token->type == TK_AMP
			|| token->type == TK_NEWLINE || token->type == TK_AND_IF
			|| token->type == TK_OR_IF) && node->type == TK_BANG
			&& node->nest == 0)
			node->full = 1;
		if (token->type == TK_PIPE && node->type == TK_BANG && node->full == 0)
			return (1);
	}
	return (0);
}

int		add_bang(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	DG("add bang");
	token = (*lst)->content;
	node = (*ast)->item;
	if ((token->type == TK_CASE || token->type == TK_WHILE
		|| token->type == TK_IF || token->type == TK_UNTIL
		|| token->type == TK_FOR || token->type == SUBSHELL
		|| token->type == TK_LBRACE) && node->type == TK_BANG)
		node->nest++;
	if ((token->type == TK_DONE || token->type == TK_ESAC
		|| token->type == TK_FI || token->type == TK_RBRACE
		|| token->type == TK_PAREN_CLOSE)
		&& node->type == TK_BANG && node->nest > 0)
		node->nest--;
	return (add_cmd(&(*ast)->right, lst));
}

int		add_bang_sep(t_btree **ast, t_list **lst)
{
	return (add_sep(&(*ast)->right, lst));
}
