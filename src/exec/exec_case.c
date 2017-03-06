/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 15:29:22 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_case(t_btree **ast)
{
	t_astnode	*node;
	char		*av;
	t_exec		*exec;

	(void)ast;
	exec = &data_singleton()->exec;
	exec->attrs &= ~EXEC_CASE_BRANCH;

	node = (*ast)->item;
	av = node->data.str;
//	av = token_to_argv(node);
	exec->case_pattern = av;
	return (0);
}
