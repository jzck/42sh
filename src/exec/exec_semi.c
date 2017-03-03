/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_semi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:52:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:10:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_semi(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	push(&exec->op_stack, TK_SEMI);
	ft_exec(&(*ast)->left);
	exec->attrs &= ~EXEC_AOL_MASK;
	ft_exec(&(*ast)->right);
//	btree_delone(ast, &ast_free);
	return (0);
}
