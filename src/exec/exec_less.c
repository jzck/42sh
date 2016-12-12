/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 18:03:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_less(t_btree **ast)
{
	t_astnode	*node;
	int			fd;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_RDONLY);
	data_singleton()->exec.fdin = fd;
	ft_exec(&(*ast)->left);
	data_singleton()->exec.fdin = STDIN;
	btree_delone(ast, &ast_free);
	return (0);
}
