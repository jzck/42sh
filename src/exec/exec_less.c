/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/30 20:56:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_less(t_btree **ast)
{
	t_astnode	*node;
	t_process	*p;
	int			fd;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_RDONLY);
	data_singleton()->exec.process.fdin = fd;
	/* ft_strappend(&data->exec.process.command, "<"); */
	/* ft_strappend(&data->exec.process.command, node->data.redir.word.word); */
	ft_exec(&(*ast)->left);
	data_singleton()->exec.process.fdin = STDIN;
	/* data->exec.process.command = NULL; */

	p = &data_singleton()->exec.process;
	if (!(p->script & SCRIPT_LOOP))
		btree_delone(ast, &ast_free);
	return (0);
}
