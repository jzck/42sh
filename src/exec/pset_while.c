/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 12:39:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 16:26:47 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_while(t_process *p, t_btree *ast)
{
	p->data.d_while.condition = btree_map(ast->left, &node_copy);
	p->data.d_while.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_WHILE;
	return (0);
}
