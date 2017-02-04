/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:03:28 by ariard            #+#    #+#             */
/*   Updated: 2017/02/04 15:51:24 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		delete_all_newline(t_list **start, t_list **lst)
{
	t_token		*token;

	while ((*lst))
	{
		token = (*lst)->content;
		if (token->type & TK_NEWLINE)
			ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
		else
			break;
		(*lst) = (*lst)->next;
	}
	return (0);
}

int		parse_while(t_btree **ast, t_list **start, t_list **lst)
{
	t_list		*temp;
	t_astnode	*node;
	t_token		*token;
	int			nest;

	token = (*lst)->content;
	node = (*ast)->item;
	node->type = TK_WHILE;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	while (((*lst) = (*lst)->next))
		if ((token = (*lst)->content)->type & TK_DO)
			break;
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->left, start);

	delete_all_newline(start, &temp);

	(*lst) = temp;
	*start = temp;
	nest = 1;
	while (((*lst) = (*lst)->next))
	{
		token = (*lst)->content;
		if (token->type & TK_DO)
			nest++;
		else if (token->type & TK_DONE)
			nest--;
		if (nest == 0)
			break;
	}
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	ft_parse(&(*ast)->right, start);
	*start = temp;
	return (0);
}
