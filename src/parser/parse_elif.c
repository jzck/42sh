/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:50:54 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 17:54:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		parse_after_elif(t_btree **ast, t_list **lst)
{
	t_list		*temp;
	t_list		*prev_prev;
	t_list		*prev;
	t_token		*token;
	int			nest;

	temp = (*lst);
	nest = 0;
	while ((temp = temp->next))
	{
		token = temp->content;
		if (nest == 0 && (token->type & TK_ELIF))
			break;
		else if (token->type & TK_IF)
			nest++;
		else if (token->type & TK_FI)
			nest--;
		prev_prev = prev;
		prev = temp;
	}
	prev_prev->next = NULL;
	if (prev)
		ft_parse(ast, &prev);
	return (0);
}

static int		parse_loop(t_btree **ast, t_list **start, t_list **lst)
{
	t_token		*token;
	t_list		*temp;
	int			nest;

	nest = 0;
	while ((*lst))
	{
		token = (*lst)->content;
		if (token->type & TK_THEN)
			nest++;
		else if (token->type & TK_ELIF)
			nest--;
		if (nest == 1 && (token->type & TK_THEN))
			break;
		*lst = (*lst)->next;
	}
	temp = (*lst)->next;
	(*lst)->next = NULL;
	ft_lst_delif(start, (*lst)->content, &ft_addrcmp, &token_free);
	delete_newline(start, &temp);
	ft_parse(&(*ast)->right, &temp);
	ft_parse(&(*ast)->left, start);
	return (0);
}

int				parse_elif(t_btree **ast, t_list **start, t_list **lst)
{
		t_btree		*new_ast;

		parse_after_elif(ast, lst);
		parse_head(ast, &new_ast, start, lst);
		*start = *lst;
		parse_loop(&new_ast, start, lst);
		return (0);
}		
