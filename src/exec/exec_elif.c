/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_elif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:08:53 by ariard            #+#    #+#             */
/*   Updated: 2017/03/15 02:04:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_elif(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	if (EXEC_IS_IF_BRANCH(exec->attrs))
		return (0);
	ft_exec(&(*ast)->left);
	if (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0") == 0)
	{
		exec->attrs |= EXEC_IF_BRANCH;
		ft_exec(&(*ast)->right);
	}
	return (0);
}
