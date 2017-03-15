/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:45:15 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 18:57:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree		*is_function(t_process *p)
{
	t_list		*tmp;
	t_btree		**ast;
	char		**av;

	tmp = data_singleton()->lst_func;
	while (tmp)
	{
		ast = tmp->content;
		if (!*ast)
			return (NULL);
		av = token_to_argv(((t_astnode *)(*ast)->item)->data.cmd.token, 1);
		if (!av || !av[0])
			return (NULL);
		if (!ft_strcmp(av[0], p->data.cmd.av[0]))
			return (btree_map((*ast)->right, node_copy));
		tmp = tmp->next;
	}
	return (NULL);
}
