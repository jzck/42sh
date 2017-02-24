/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 23:43:07 by ariard            #+#    #+#             */
/*   Updated: 2017/02/25 00:28:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			isfunc(t_btree **ast, t_list **lst)
{
	t_astnode	*node;
	t_token		*token;

	node = NULL;
	token = (*lst)->content;
	if (*ast)
	{
		node = (*ast)->item;
		if (node->type == TK_WORD && token->type == CLOSE_LIST)
			node->type = FNAME;
		if (node->type == FNAME && node->full == 0)
			return (1);
		if (isfunc(&(*ast)->right, lst) == 1)
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
	if (token->type == CLOSE_LIST && node->nest == 0)
		return (0);
	if ((token->type == TK_CASE || token->type == TK_WHILE || token->type == TK_IF
		|| token->type == TK_UNTIL || token->type == TK_FOR
		|| token->type == SUBSHELL || token->type == TK_LBRACE) 
		&& node->type == FNAME)
		node->nest++;
	if ((token->type == TK_DONE || token->type == TK_ESAC || token->type ==  TK_FI
		|| token->type == TK_RBRACE || token->type == TK_PAREN_OPEN)
		&& node->type == FNAME && node->nest > 0)
		node->nest--;
	if ((token->type == TK_DONE || token->type == TK_ESAC || token->type ==  TK_FI
		|| token->type == TK_RBRACE || token->type == TK_PAREN_OPEN)
		&& node->type == FNAME && node->nest == 0)
		node->full = 1;
	return (add_cmd(&(*ast)->right, lst));
}

int		add_func_sep(t_btree **ast, t_list **lst)
{
	return (add_sep(&(*ast)->right, lst));
}


