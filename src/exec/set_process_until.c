/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_until.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:22:24 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 22:22:36 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_process_until(t_process *p, t_btree *ast, t_cmd *cmd)
{
	(void)cmd;
	p->data.d_while.condition = ast_copy(ast->left);
	p->data.d_while.content = ast_copy(ast->right);
	p->type = PROCESS_UNTIL;
	return (0);
}
