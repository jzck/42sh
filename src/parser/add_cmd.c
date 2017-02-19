/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 20:49:15 by ariard            #+#    #+#             */
/*   Updated: 2017/02/19 18:46:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			add_cmd(t_btree **ast, t_list **lst)
{
	t_token		*token;
	t_astnode	*node;
	char		**my_tab;

	DG("add cmd");
	if (!*ast)
		gen_node(ast);
	else if (isdir(ast))
		return (add_file(ast, lst));	
	else if (isloop(ast))
		return (add_loop_cmd(ast, lst));
	else if (iscondition(ast))
		return (add_condition_cmd(ast, lst));
	else if ((node = (*ast)->item)->type != TK_DO && node->type != TK_THEN)
		return (add_cmd(&(*ast)->right, lst));
	my_tab = NULL;
	token = (*lst)->content;
	node = (*ast)->item;
	node->type = token->type;
	if (token->type == TK_N_WORD)
	{
		my_tab = ft_sstradd(my_tab, token->data);
		my_tab = ft_sstradd(my_tab, (char *)token->esc);
//		ft_ld_pushback(&node->data.token, my_tab);
	}
	return (0);
}
