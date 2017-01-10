/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_great.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:14:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_great(t_btree **ast)
{
	t_astnode	*node;
	int			fd;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	data_singleton()->exec.process.fdout = fd;
	ft_exec(&(*ast)->left);
	data_singleton()->exec.process.fdout = STDOUT;
	btree_delone(ast, &ast_free);
	return (0);
}
