/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 16:30:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_if(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;

	/* data_singleton()->exec.process.if_branch = 0; */
	exec->attrs &= ~EXEC_IF_BRANCH;
	ft_exec(&(*ast)->left);
	/* if (data_singleton()->exec.process.status == 1) */
	if (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0") == 0)
	{
		/* data_singleton()->exec.process.if_branch = 1; */
		exec->attrs |= EXEC_IF_BRANCH;
		ft_exec(&(*ast)->right);
	}
	return (0);
}
