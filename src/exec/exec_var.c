/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:12:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/24 19:44:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_var(t_btree **ast)
{
	t_astnode	*node;
	char		**av;
	char		*var;
	char		*value;
	char		*equal;

	node = (*ast)->item;
	pop(&data_singleton()->exec.op_stack);
	if (!(av = token_to_argv(node->data.cmd.token, 1)))
		return (0);
	var = av[0];
	if ((equal = ft_strchr(av[0], '=')))
		*equal = 0;
	value = equal ? equal + 1 : NULL;
	builtin_setenv("internal", (char*[]){"local", var, value, 0}, NULL);
	ft_sstrfree(av);
	ft_exec(&(*ast)->right);
	return (0);
}
