/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:50:54 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 19:22:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		parse_after_else(t_btree **ast, t_list **lst)
{
	t_list		*temp;

	temp = (*lst);
	while ((temp = temp->next));
	if (temp)
		ft_parse(ast, &temp);
	return (0);
}

static int		parse_loop(t_btree **ast, t_list **start, t_list **lst)
{
	delete_newline(start, lst);
	ft_parse(&(*ast)->right, lst);
	return (0);
}

int				parse_else(t_btree **ast, t_list **start, t_list **lst)
{
		t_btree		*new_ast;

		parse_after_else(ast, lst);
		parse_head(ast, &new_ast, start, lst);
		*start = *lst;
		parse_loop(&new_ast, start, lst);
		return (0);
}
