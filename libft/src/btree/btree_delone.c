/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:45:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 12:48:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_delone(t_btree **root, void (*del)(void *, size_t))
{
	if (root && *root)
	{
		if (del)
			(*del)((*root)->item, (*root)->content_size);
		free(*root);
		*root = NULL;
	}
}
