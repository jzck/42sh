/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:08:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/18 13:41:48 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_is_hash(t_process *p)
{
	t_list	*list;
	int		id;

	id = ft_hash_str(p->av[0]);
	if (!g_hash[id])
		return (0);
	list = g_hash[id];
	while (list)
	{
		if (!ft_strcmp(((t_hash *)list->content)->key, p->av[0]))
		{
			p->path = ft_strdup(((t_hash *)list->content)->path);
			return (1);
		}
		list = list->next;
	}
	return (0);
}
