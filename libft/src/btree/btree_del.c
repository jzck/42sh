/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:43:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 11:53:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_del(t_btree **root, void (*del)(void *, size_t))
{
	if (root && *root && del)
	{
		btree_del(&(*root)->left, del);
		btree_del(&(*root)->right, del);
		btree_delone(root, del);
	}
}
