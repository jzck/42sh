/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:55:07 by ariard            #+#    #+#             */
/*   Updated: 2017/03/04 18:06:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_else(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	if (EXEC_IS_IF_BRANCH(exec->attrs))
		return (0);
	exec->attrs |= EXEC_IF_BRANCH;
	ft_exec(&(*ast)->left);
	return (0);
}
