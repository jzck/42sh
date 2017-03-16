/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:50:46 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 18:43:15 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree		*btree_map(t_btree *root, void *(*f)(void *))
{
	t_btree		*new;

	if (!root)
		return (NULL);
	new = btree_create_node((*f)(root->item), root->content_size);
	new->left = btree_map(root->left, f);
	new->right = btree_map(root->right, f);
	return (new);
}
