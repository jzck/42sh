/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ampersand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:01:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 18:24:12 by jhalford         ###   ########.fr       */
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
	ft_exec(&(*ast)->left);
	exec->attrs &= ~EXEC_BG;
	ft_exec(&(*ast)->right);
	/* if (SH_HAS_JOBC(data_singleton()->opts)) */
	/* 	data_singleton()->exec.job.attributes |= JOB_BG; */
	/* ft_exec(&(*ast)->left); */
	/* if (SH_HAS_JOBC(data_singleton()->opts)) */
	/* 	data_singleton()->exec.job.attributes &= ~JOB_BG; */
	/* ft_exec(&(*ast)->right); */

//	btree_delone(ast, &ast_free);
	return (0);
}
