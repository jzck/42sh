/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:02:01 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 00:14:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_process_subshell(t_process *p, t_btree *ast, t_cmd *cmd)
{
	(void)cmd;
	p->data.subshell.content = ast_copy(ast->right);
	p->type = PROCESS_SUBSHELL;
	return (0);
}
