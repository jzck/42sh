/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:50:46 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 15:49:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

t_btree		*btree_map(t_btree *root, void *(*f)(void *))
{
	t_btree		*new;

	if (!root)
		return (NULL);
	if (!(new = (t_btree *)ft_malloc(sizeof(*new))))
		return (NULL);
	new->item = (*f)(root->item);
	new->left = btree_map(root->left, f);
	new->right = btree_map(root->right, f);
	return (new);
}
