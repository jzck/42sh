/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_brace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:07:34 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:58:50 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_brace(t_process *p, t_btree *ast)
{
	p->data.subshell.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_BRACE;
	return (0);
}
