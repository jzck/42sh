/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_or_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:06:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:40:15 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_or_if(t_btree **ast)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	push(&exec->op_stack, TK_OR_IF);
	ft_exec(&(*ast)->left);
	exec->attrs &= ~EXEC_AND_IF;
	exec->attrs = EXEC_OR_IF;
	ft_exec(&(*ast)->right);
	return (0);
}
