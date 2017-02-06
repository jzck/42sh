/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_if.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:15:23 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 17:46:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		parse_after_condition(t_btree **ast, t_list **start, t_list **lst)
{
	t_list	*temp;
	t_list	*del;
	t_token	*token;
	int		nest;

	temp = (*lst);
	nest = 0;	
	while (temp)
	{
		token = temp->content;
		if (token->type & TK_IF)
			nest++;
		else if (token->type & TK_FI)
			nest--;
		if (nest == 0 && (token->type & TK_FI))
			break;		
		temp = temp->next;
	}
	del = temp;
	temp = temp->next;
	del->next = NULL;
	ft_lst_delif(start, del->content, &ft_addrcmp, &token_free);
	if (temp)
		ft_parse(ast, &temp);
	return (0);
}

static int	parse_head_condition(t_btree **ast, 
			t_btree **new_ast, t_list **start, t_list **lst)
{
	t_btree 	*father;
	t_token		*token;
	t_astnode	*node;
	t_astnode	item;

	father = *ast;
	while (father->left)
		father = father->left;
	*new_ast = btree_create_node(&item, sizeof(item));
	((t_astnode *)(*new_ast)->item)->data.token = NULL;
	node = (*ast)->item;
	if (node->type > 0)
		father->left = *new_ast;
	else
		*new_ast = *ast;

	token = (*lst)->content;
	node = (*new_ast)->item;
	node->type = token->type;
	token->type = TK_ELIF;
	ft_parse(&(*new_ast)->right, start);
	return (0);
}


int			parse_if(t_btree **ast, t_list **start, t_list **lst)
{
	t_btree		*new_ast;
	
	parse_after_condition(ast, start, lst);
	parse_head_condition(ast, &new_ast, start, lst);
	return (0);
}
