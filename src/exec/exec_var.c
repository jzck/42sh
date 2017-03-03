/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 20:32:27 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_var(t_btree **ast)
{
	t_astnode	*node;
	char		**av;	

	node = (*ast)->item;
	av = token_to_argv(node->data.cmd.token, 0);
	builtin_setenv("setenv", av, data_singleton()->local_var);
	return (0);
}
