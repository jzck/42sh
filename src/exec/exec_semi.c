/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_semi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:52:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 15:55:43 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_semi(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	push(&exec->op_stack, TK_SEMI);
	ft_exec(&(*ast)->left);
	exec->attrs &= ~EXEC_AOL_MASK;
	ft_exec(&(*ast)->right);
	return (0);
}
