/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 13:43:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/08/25 17:46:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

int	btree_level_count(t_btree *root)
{
	return (root
			? 1 + FT_MAX(btree_level_count(root->left),
				btree_level_count(root->right))
			: 0);
}
