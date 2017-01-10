/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:14:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_less(t_btree **ast)
{
	t_astnode	*node;
	int			fd;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_RDONLY);
	data_singleton()->exec.process.fdin = fd;
	/* ft_strappend(&data->exec.process.command, "<"); */
	/* ft_strappend(&data->exec.process.command, node->data.redir.word.word); */
	ft_exec(&(*ast)->left);
	data_singleton()->exec.process.fdin = STDIN;
	/* data->exec.process.command = NULL; */
	btree_delone(ast, &ast_free);
	return (0);
}
