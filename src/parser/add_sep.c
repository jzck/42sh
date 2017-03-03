/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 19:12:07 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 14:27:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			add_sep(t_btree **ast, t_list **lst)
{	
	t_token		*token;
	t_astnode	*node;
	t_btree		*new_node;
	
	DG("add sep");
	if (isloop(ast, lst) == 1)
		return (add_loop_sep(ast, lst));
	else if (iscondition(ast, lst) == 1)
		return (add_condition_sep(ast, lst));
	else if (iscase(ast, lst) == 2)
		return (add_case_sep(ast, lst));
	else if (issubshell(ast, lst))
		return (add_subshell_sep(ast, lst));
	else if (isfunc(ast, lst))
		return (add_func_sep(ast, lst));
	if (!*ast)
		gen_node(ast);
	token = (*lst)->content;
//watch != TK_DO
	new_node = NULL;
	gen_node(&new_node);
	join_ast(ast, &new_node);
	node = (new_node)->item;
	node->type = token->type;	
	return (0);
}
