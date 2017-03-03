/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:55:07 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 15:56:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_else(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	if (EXEC_IS_IF_BRANCH(exec->attrs))
	/* if (data_singleton()->exec.process.if_branch == 0) */
	{
		exec->attrs |= EXEC_IF_BRANCH;
		/* data_singleton()->exec.process.if_branch = 1; */
		ft_exec(&(*ast)->right);
	}
	return (0);
}
