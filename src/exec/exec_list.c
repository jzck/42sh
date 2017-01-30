/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:19:29 by ariard            #+#    #+#             */
/*   Updated: 2017/01/30 20:57:51 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_list(t_btree **ast)
{
	t_process	*p;

	p = &data_singleton()->exec.process;
	if (!(p->script & SCRIPT_LOOP))
		btree_delone(ast, &ast_free);
	return (0);
}
