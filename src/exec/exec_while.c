/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/01/30 19:30:16 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_while(t_btree **ast)
{
	t_list		*test_commands;
	t_list		*consequent_commands;
	t_astnode	*node;
	t_process	*p;

	node = ((*ast)->left)->item;
	DG("test command data '%s'", node->data.str);
	test_commands = shell_get_ast(node->data.str);
	node = ((*ast)->right)->item;
	DG("consequent command data '%s'", node->data.str);
	consequent_commands = shell_get_ast(node->data.str);

	p = &data_singleton()->exec.process;
	p->script &= ~SCRIPT_LOOP;

//	while (ft_test(test_commands)) 
//		ft_exec(consequent_commands)
//	del tree (test_commands);
//	del tree (test_commands);
	btree_delone(ast, &ast_free);
	return (0);
}
