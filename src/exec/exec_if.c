/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_if.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:31 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 15:12:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_if(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;

	exec->attrs &= ~EXEC_IF_BRANCH;
	ft_exec(&(*ast)->left);
	if (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0") == 0)
	{
		exec->attrs |= EXEC_IF_BRANCH;
		ft_exec(&(*ast)->right);
	}
	return (0);
}
