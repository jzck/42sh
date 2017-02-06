/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:03:28 by ariard            #+#    #+#             */
/*   UpdatGed: 2017/02/05 18:28:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		delete_newline(t_list **start, t_list **lst)
{
	t_token		*token;
	t_list		*del;

	while ((*lst))
	{
		token = (*lst)->content;
		del = *lst;
		if (token->type & TK_NEWLINE)
			ft_lst_delif(start, del->content, &ft_addrcmp, &token_free);
		else
			break;
		*lst = (*lst)->next;
	}
	return (0);
}

static int		parse_after_loop(t_btree **ast, t_list **start, t_list **lst)
{
	t_list	*temp;
	t_list	*del;
	t_token	*token;
	int		nest;

	temp = (*lst);
	nest = 0;
	while ((temp = temp->next))
	{
		token = temp->content;
		if (token->type & TK_DO)
			nest++;
		else if (token->type & TK_DONE)
			nest--;
		if (nest == 0 && (token->type & TK_DONE))
			break;
	}
	del = temp;
	temp = temp->next;
	del->next = NULL;
	ft_lst_delif(start, del->content, &ft_addrcmp, &token_free);
	if (temp)
		ft_parse(ast, &temp);
	return (0);
}

int		parse_head(t_btree **ast, 
					t_btree **new_ast, t_list **start, t_list **lst)
{
	t_btree		*father;
	t_token		*token;
	t_list		*del;
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
	del = (*lst);
	*lst = (*lst)->next;
	//check that//
	del->next = NULL;
	ft_lst_delif(start, del->content, &ft_addrcmp, &token_free);
	delete_newline(start, lst);
	return (0);
}

static int		parse_loop(t_btree **ast, t_list **start, t_list **lst)
{
	t_token		*token;
	t_list		*temp;
	t_list		*new_start;
	int			nest;

	nest = 0;
	while ((*lst)->next)
		*lst = (*lst)->next;
	new_start = *start;
	ft_lst_reverse(start);
	temp = *lst;
	while ((*lst))
	{
		token = (*lst)->content;
		if (token->type & TK_DO)
			nest++;
		else if (token->type & TK_DONE)
			nest--;
		if (nest == 1 && (token->type & TK_DO))
			break;
		*lst = (*lst)->next;
	}
	ft_lst_reverse(&temp);
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(&new_start, (*lst)->content, &ft_addrcmp, &token_free);	
	delete_newline(start, &temp);	
	ft_parse(&(*ast)->right, &temp);
	ft_parse(&(*ast)->left, &new_start);
	return (0);
}

int			parse_while(t_btree **ast, t_list **start, t_list **lst)
{
	t_btree		*new_ast;

	parse_after_loop(ast, start, lst);
	parse_head(ast, &new_ast, start, lst);
	parse_loop(&new_ast, start, lst);
	return (0);
}
