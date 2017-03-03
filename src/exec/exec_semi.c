/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_semi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:52:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:01:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_semi(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	DG();
	push(&exec->op_stack, TK_SEMI);
	DG();
	ft_exec(&(*ast)->left);
	DG();
	exec->attrs &= ~EXEC_AOL_MASK;
	ft_exec(&(*ast)->right);
//	btree_delone(ast, &ast_free);
	return (0);
}
