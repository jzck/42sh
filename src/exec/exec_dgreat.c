/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dgreat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:15:13 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 20:55:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_dgreat(t_btree **ast)
{
	t_astnode	*node;
	t_process	*p;
	int			fd;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_WRONLY | O_APPEND | O_CREAT, 0644);
	data_singleton()->exec.process.fdout = fd;
	ft_exec(&(*ast)->left);
	data_singleton()->exec.process.fdout = STDOUT;

	p = &data_singleton()->exec.process;
	if (!(p->script & SCRIPT_LOOP))
		btree_delone(ast, &ast_free);
	return (0);
}
