/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_case_branch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:33:45 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 01:21:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_case_branch(t_btree **ast)
{
	t_astnode	*node;
	char		**av;
	t_exec		*exec;

	DG("exec branch case");
	exec = &data_singleton()->exec;
	if (EXEC_IS_CASE_BRANCH(exec->attrs))
		return (0);
	node = (*ast)->item;
	av = token_to_argv(node->data.cmd.token, 1);
	DG("compare pattern %s ", av[0]);
	DG("and case %s", ((char **)exec->case_pattern)[0]);
	DG();
	if (ft_strcmp(av[0], ((char **)exec->case_pattern)[0]) == 0)
	{ 
		exec->attrs |= EXEC_CASE_BRANCH;
		 ft_exec(&(*ast)->right);
	}
	return (0);
}
