/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_while.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:38:10 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:57:55 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_process_while(t_process *p, t_btree *ast, t_cmd *cmd)
{
	(void)cmd;
	p->data.d_while.condition = ast_copy(ast->left);
	p->data.d_while.content = ast_copy(ast->right);
	p->type = PROCESS_WHILE;
	return (0);
}
