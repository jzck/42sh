/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ampersand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:01:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 15:36:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_ampersand(t_btree **ast)
{
	t_exec	*exec;

	if (!SH_HAS_JOBC(data_singleton()->opts))
		return (exec_semi(ast));
	exec = &data_singleton()->exec;
	push(&exec->op_stack, TK_AMP);
	exec->job.attrs |= JOB_BG;
	ft_exec(&(*ast)->left);
	exec->attrs &= ~EXEC_AOL_MASK;
	exec->job.attrs &= ~JOB_BG;
	ft_exec(&(*ast)->right);
	return (0);
}
