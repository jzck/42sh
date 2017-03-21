/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:45:15 by wescande          #+#    #+#             */
/*   Updated: 2017/03/21 21:17:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree		*is_function(t_process *p)
{
	t_list		*tmp;
	t_btree		**ast;
	char		**av;
	int			ret;

	tmp = data_singleton()->lst_func;
	ret = 1;
	while (tmp && ret)
	{
		ast = tmp->content;
		if (!*ast)
			return (NULL);
		av = token_to_argv(((t_astnode *)(*ast)->item)->data.cmd.token, 1);
		if (av && av[0] && !ft_strcmp(av[0], p->data.cmd.av[0]))
			ret = 0;
		ft_tabdel(&av);
		tmp = tmp->next;
	}
	if (!ret)
		return (btree_map((*ast)->right, node_copy));
	return (NULL);
}
