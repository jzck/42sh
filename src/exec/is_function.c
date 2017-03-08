/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 02:45:15 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 03:22:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree		*is_function(t_process *p)
{
	t_list	*tmp;

	tmp = data_singleton()->lst_func;
	while (tmp)
	{
		if (!ft_strcmp(((t_astnode *)tmp->content)->data.str, p->data.cmd.av[0]))
			return (btree_map(p->data.subshell.content, node_copy));
		tmp = tmp->next;
	}
	return (NULL);
}
