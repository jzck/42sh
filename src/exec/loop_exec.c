/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 21:02:10 by ariard            #+#    #+#             */
/*   Updated: 2017/01/31 19:27:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		loop_exec(t_list *list_ast)
{

//	DG("begin exec loop");
//	ft_print_all_ast(*list_ast);
	while (list_ast)
	{
		if (ft_exec((t_btree **)list_ast->content))
			return (1);
		list_ast = list_ast->next;
	}
	return (0);
}
