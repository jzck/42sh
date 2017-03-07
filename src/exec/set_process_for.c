/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process_for.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:38:05 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 22:00:34 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		set_process_for(t_process *p, t_btree *ast, t_cmd *cmd)
{
	(void)cmd;
	p->data.d_for.list_word = ft_ld_copy(((t_astnode *)ast->item)->data.cmd.wordlist, tab_esc_copy);
	p->data.d_for.content = ast_copy(ast->right);
	p->type = PROCESS_FOR;
	return (0);
}
