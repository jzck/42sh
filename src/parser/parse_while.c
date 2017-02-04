/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:03:28 by ariard            #+#    #+#             */
/*   Updated: 2017/02/05 00:40:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		delete_all_newline(t_list **lst)
{
	t_token		*token;
	t_list		*start;

	while ((*lst))
	{
		token = (*lst)->content;
		start = *lst;
		(*lst) = (*lst)->next;
		if (token->type & TK_NEWLINE)
			ft_lstdelone(&start, &token_free);
		else
			break;
	}
	return (0);
}

int		parse_while(t_btree **ast, t_list **start, t_list **lst)
{
	t_list		*temp;
	t_list		*temp4;
	t_btree		*temp2;
	t_btree		*temp3;
	t_astnode	*node;
	t_astnode	item;
	t_token		*token;
	int			nest;

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
	temp4 = temp;
	temp = temp->next;
	temp4->next = NULL;
	ft_lst_delif(start, temp4->content, &ft_addrcmp, &token_free);
	if (temp)
		ft_parse(ast, &temp);
	temp2 = *ast;
	while (temp2->left)
		temp2 = temp2->left;
	temp3 = btree_create_node(&item, sizeof(item));
	((t_astnode *)(*ast)->item)->data.token = NULL;
	temp2->left = temp3;

	node = temp3->item;
	node->type = TK_WHILE;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);

	while (((*lst) = (*lst)->next))
		if ((token = (*lst)->content)->type & TK_DO)
			break;
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(&(temp3)->left, start);

	return (0);

	delete_all_newline(&temp);
	ft_parse(&(temp3)->right, &temp);		

	return (0);
}
