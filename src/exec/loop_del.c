/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 22:39:20 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 22:51:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		loop_del(t_list *list_ast)
{
	t_list	*temp;

	while (list_ast)
	{
		btree_del((t_btree **)list_ast->content, &ast_free);
		temp = list_ast;
		list_ast = list_ast->next;
		ft_lstdelone(&temp, NULL);
	}
	return (0);
}
