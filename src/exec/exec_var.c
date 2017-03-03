/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 16:28:41 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_var(t_btree **ast)
{
	t_astnode	*node;
	char		**av;	

	node = (*ast)->item;
	/* av = token_to_argv(node); */
	builtin_setenv("setenv", av, data_singleton()->local_var);
	return (0);
}
