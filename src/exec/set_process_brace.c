/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_brace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:07:34 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 19:08:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int		set_process_brace(t_process *p, t_btree *ast)
{
	p->data.subshell.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_BRACE;
	return (0);
}
