/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 15:29:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_case_branch(t_btree **ast)
{
	t_astnode	*node;
	char		*av;
	t_exec	*exec;

	(void)ast;
	exec = &data_singleton()->exec;

	DG("case");
	if (EXEC_IS_CASE_BRANCH(exec->attrs))
		return (0);
	DG("case2");
	node = (*ast)->item;
	av = node->data.str;
//	av = token_to_argv(node);
	if (ft_strcmp(av, exec->case_pattern) == 0)
	{ 
		exec->attrs |= EXEC_CASE_BRANCH;
	 	ft_exec(&(*ast)->right);
	} 		
	return (0);
}
