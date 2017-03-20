/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:38:05 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 15:59:25 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_for(t_process *p, t_btree *ast)
{
	p->data.d_for.token = ft_ld_copy(((t_astnode *)ast->item)->data.cmd.token,
																tab_esc_copy);
	p->data.d_for.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_FOR;
	return (0);
}
