/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:12:05 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 14:40:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	set_var(char *stream, char **var, char **value)
{
	*var = ft_strdupchr(stream, '=');
	stream += ft_strlenchr(stream, '=') + 1;
	*value = ft_strdup(stream);
	return (0);
}

int		exec_var(t_btree **ast)
{
	t_astnode	*node;
	char		**av;	
	char		*var;
	char		*value;
	
	node = (*ast)->item;
	av = token_to_argv(node->data.cmd.token, 1);
	set_var(av[0], &var, &value);	
	builtin_setenv("setenv", (char*[]){var, value, 0}, data_singleton()->local_var);
	return (0);
}
