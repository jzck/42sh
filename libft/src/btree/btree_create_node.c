/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 13:43:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 00:35:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree	*btree_create_node(void const *item, size_t content_size)
{
	t_btree	*new;

	if (!(new = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	new->left = 0;
	new->right = 0;
	if (!item)
	{
		new->content_size = 0;
		new->item = NULL;
	}
	else
	{
		new->content_size = content_size;
		new->item = ft_memalloc(content_size + 1);
		ft_memcpy(new->item, item, content_size);
	}
	return (new);
}
