/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 23:43:07 by ariard            #+#    #+#             */
/*   Updated: 2017/03/24 23:23:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			isfunc_name(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == CMD && token->type == TK_PAREN_OPEN)
		{
			node->type = FNAME;
			return (1);
		}
	}
	return (0);
}

int			isfunc(t_btree **ast, t_list **lst)
{
	t_astnode	*node;

	(void)lst;
	node = NULL;
	if (*ast)
	{
		node = (*ast)->item;
		if ((node->type == TK_NEWLINE || node->type == TK_SEMI
			|| node->type == TK_AMP || node->type == TK_PIPE)
			&& isfunc(&(*ast)->right, lst) == 1)
			return (1);
		if (node->type == FNAME && node->full == 0)
			return (1);
	}
	return (0);
}

int			add_func_cmd(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	if ((token->type == TK_CASE || token->type == TK_WHILE
		|| token->type == TK_IF || token->type == TK_UNTIL
		|| token->type == TK_FOR || token->type == SUBSHELL
		|| token->type == TK_LBRACE || token->type == TK_PAREN_OPEN)
		&& node->type == FNAME)
		node->nest++;
	if ((token->type == TK_DONE || token->type == TK_ESAC
		|| token->type == TK_FI || token->type == TK_RBRACE
		|| token->type == TK_PAREN_CLOSE) && node->type == FNAME
		&& node->nest > 0)
		node->nest--;
	if ((token->type == TK_DONE || token->type == TK_ESAC
		|| token->type == TK_FI || token->type == TK_RBRACE
		|| token->type == TK_PAREN_CLOSE) && node->type == FNAME
		&& node->nest == 0)
		node->full = 1;
	return (add_cmd(&(*ast)->right, lst));
}
