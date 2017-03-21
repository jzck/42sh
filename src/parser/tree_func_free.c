/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_func_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:02:54 by ariard            #+#    #+#             */
/*   Updated: 2017/03/21 19:44:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tree_func_free(void *data, size_t content_size)
{
	t_btree		**root;

	(void)content_size;
	root = data;
	btree_del(root, &ast_free);
	free(root);
}
