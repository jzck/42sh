/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:56:55 by ariard            #+#    #+#             */
/*   Updated: 2017/02/04 22:20:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	get_simple_instruction(t_list **start, t_list **lst)
{
	t_list	*temp;

	DG("simple instruction");
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	(*lst) = temp;
	return (0);
}

static int	get_compound_instruction(t_list **start, t_list **lst)
{
	t_list	*temp;
	t_token	*token;
	int		nest;

	DG("compound instruction");
	nest = 0;
	while (((*lst) = (*lst)->next))
	{
		token = (*lst)->content;
		if (token->type & TK_DO)
			nest++;
		else if (token->type & TK_DONE)
			nest--;
		if (nest == 0 && token->type & TK_DONE)
			break;
	}
	while (((*lst) = (*lst)->next))
	{
		token = (*lst)->content;
		if (token->type & (TK_NEWLINE | TK_SEMI))
			break;
	}
	if ((*lst))
	{
		temp = (*lst)->next;
		(*lst)->next = NULL;
		ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
		*lst = temp;
	}
	return (0);
}
	
int			get_instruction(t_list **lst)
{
	t_token		*token;
	t_list		*start;

	start = *lst;
	while ((*lst))
	{
		token = (*lst)->content;
		if (token->type & TK_NEWLINE)
			return (get_simple_instruction(&start, lst));
		else if (token->type & TK_WHILE)
			return (get_compound_instruction(&start, lst));
		(*lst) = (*lst)->next;
	}
	return (0);
}
