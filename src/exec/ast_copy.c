/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:44:42 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:25:15 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_btree		*ast_copy(t_btree *tree)
{
	t_btree		*node;

	if (!tree)
		return (NULL);
	node = btree_create_node(tree->item, tree->content_size);
	node->left = ast_copy(tree->left);
	node->right = ast_copy(tree->right);
	return (node);
}
