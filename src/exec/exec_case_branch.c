/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 16:28:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_case_branch(t_btree **ast)
{
	t_astnode	*node;
	/* char		**av; */
	t_exec	*exec;

	exec = &data_singleton()->exec;
	/* if (data_singleton()->exec.process.case_branch == 1) */
	if (EXEC_IS_CASE_BRANCH(exec->attrs))
		return (0);
	node = (*ast)->item;
	/* av = token_to_argv(node); */
	/* if (ft_strcmp(av[0], data_singleton()->exec.process.case_pattern) == 1) */
	/* { */
	/* 	data_singleton()->exec.process.case_branch = 1; */
	/* 	ft_exec(&(*ast)->right); */
	/* } */		
	return (0);
}
