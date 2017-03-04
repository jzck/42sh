/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/04 18:18:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_case(t_btree **ast)
{
	t_astnode	*node;
	/* char		**av; */
	t_exec	*exec;

	return (0);
	exec = &data_singleton()->exec;
	/* data_singleton()->exec.process.case_branch = 0; */
	exec->attrs |= EXEC_CASE_BRANCH;

	node = (*ast)->item;
	/* av = token_to_argv(node); */
	/* data_singleton()->exec.process.case_pattern = av[0]; */
	/* exec->case_pattern = av[0]; */
	return (0);
}
