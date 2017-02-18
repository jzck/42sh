/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:08:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/18 16:42:12 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_is_hash(t_process *p)
{
	t_list	*list;
	t_list	*ref;
	int		id;

	id = ft_hash_str(p->av[0]);
	list = g_hash[id];
	ref = list;
	while (list)
	{
		if (!ft_strcmp(((t_hash *)list->content)->key, p->av[0]))
		{
			if (access(((t_hash *)list->content)->path, X_OK))
			{
				ref->next = list->next;
				ft_lstdelone(&list, &ft_hash_free);
				return (0);
			}
			p->path = ft_strdup(((t_hash *)list->content)->path);
			return (1);
		}
		ref = list;
		list = list->next;
	}
	return (0);
}
