/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pset_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:36:04 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 20:31:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pset_case(t_process *p, t_btree *ast)
{
	p->data.d_case.list_word = ft_ld_copy(((t_astnode *)ast->item)->data.cmd.wordlist, tab_esc_copy);
	p->data.d_case.content = btree_map(ast->right, &node_copy);
	p->type = PROCESS_CASE;
	return (0);
}
