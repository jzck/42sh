/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 13:43:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 16:12:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_insert_data(
		t_btree **root,
		void *item,
		size_t content_size,
		int (*cmpf)(void *, void *))
{
	t_btree	*node;

	if (!*root)
	{
		*root = btree_create_node(item, content_size);
		return ;
	}
	node = *root;
	if ((*cmpf)(item, node->item) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, content_size, cmpf);
		else
			node->left = btree_create_node(item, content_size);
	}
	else
	{
		if (node->right)
			btree_insert_data(&node->right, item, content_size, cmpf);
		else
			node->right = btree_create_node(item, content_size);
	}
}
