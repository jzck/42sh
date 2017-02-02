/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/02/02 16:30:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_while(t_btree **ast)
{
	t_list		**consequent_commands;
	t_astnode	*node;
	int			test;

	node = ((*ast)->right)->item;
	DG("consequent command data '%s'", node->data.str);
	consequent_commands = shell_get_ast(node->data.str);


	test = 10;
	while (test--) 
	{
		loop_exec(*consequent_commands);
		DG("end loop : '%d'", test);
	}

//	loop_del(*consequent_commands);
//	btree_delone(ast, &ast_free);	
	return (0);
}
