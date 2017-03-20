/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bang.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:46:27 by ariard            #+#    #+#             */
/*   Updated: 2017/03/20 15:41:04 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_bang(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	push(&exec->op_stack, TK_BANG);
	ft_exec(&(*ast)->left);
	ft_exec(&(*ast)->right);
	set_exitstatus(ft_atoi(ft_getenv(data_singleton()->env, "?")) ? 0 : 1, 1);
	return (0);
}
