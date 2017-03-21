/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 11:08:40 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/21 17:40:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_is_hash(char *cmd)
{
	t_list	*list;
	t_list	*ref;
	int		id;

	id = ft_hash_str(cmd);
	list = g_hash[id];
	ref = list;
	while (list)
	{
		if (!ft_strcmp(((t_hash *)list->content)->key, cmd))
		{
			if (access(((t_hash *)list->content)->path, X_OK))
			{
				ref->next = list->next;
				ft_lstdelone(&list, &ft_hash_free);
				return (NULL);
			}
			return (ft_strdup(((t_hash *)list->content)->path));
		}
		ref = list;
		list = list->next;
	}
	return (NULL);
}
