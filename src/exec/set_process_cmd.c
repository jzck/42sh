/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:06:05 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:44:40 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_process_cmd(t_process *p, t_btree *ast, t_cmd *cmd)
{
	(void)ast;
	if (!(p->data.cmd.av = token_to_argv(cmd->token, 1)))
		return (1);
	process_setexec(p);
	return (0);
}
