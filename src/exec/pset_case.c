/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:36:04 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 01:46:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_case(t_process *p, t_btree *ast)
{
	DG("set case");
	p->data.d_case.token = ft_ld_copy(((t_astnode *)ast->item)->data.cmd.token, tab_esc_copy);
	p->data.d_case.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_CASE;
	return (0);
}
