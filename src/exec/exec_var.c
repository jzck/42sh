/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:12:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/23 00:51:22 by ariard           ###   ########.fr       */
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
	DG("before");
	if (!(av = token_to_argv(node->data.cmd.token, 1)))
		return (0);
	DG("after");
	var = av[0];
	if ((equal = ft_strchr(av[0], '=')))
		*equal = 0;
	value = equal ? equal + 1 : NULL;
	builtin_setenv("internal", (char*[]){"local", var, value, 0}, NULL);
	ft_sstrfree(av);
	return (0);
}
