/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 23:43:07 by ariard            #+#    #+#             */
/*   Updated: 2017/03/15 00:26:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		isfunc_name(t_btree **ast, t_list **lst)
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
			node->data.str = ft_strdup(token->data);
			return (1);
		}
		if (node->type == FNAME && token->type == TK_PAREN_CLOSE
			&& node->nest == 0)
			return (1);
	}
	return (0);
}

int		isfunc(t_btree **ast, t_list **lst)
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

int		add_func_cmd(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	token = (*lst)->content;
	node = (*ast)->item;
	if ((token->type == TK_CASE || token->type == TK_WHILE
		|| token->type == TK_IF || token->type == TK_UNTIL
		|| token->type == TK_FOR || token->type == SUBSHELL
		|| token->type == TK_LBRACE) && node->type == FNAME)
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
	{
		node->full = 1;
		add_one_func(ast, lst);
	}
	return (add_cmd(&(*ast)->right, lst));
}

int		add_func_sep(t_btree **ast, t_list **lst)
{
	return (add_sep(&(*ast)->right, lst));
}

int		add_one_func(t_btree **ast, t_list **lst)
{
	t_btree	*func_ast;

	(void)lst;
	func_ast = btree_map(*ast, node_copy);
	ft_lsteadd(&data_singleton()->lst_func, ft_lstnew(&func_ast, sizeof(*ast)));
	return (0);
}
