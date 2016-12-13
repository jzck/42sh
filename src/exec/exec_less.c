/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:08 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 12:24:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_less(t_btree **ast)
{
	t_astnode	*node;
	int			fd;
	t_data		*data;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_RDONLY);
	data_singleton()->jobc.process.fdin = fd;
	ft_strappend(&data->jobc.process.command, "<");
	ft_strappend(&data->jobc.process.command, node->data.redir.word.word);
	ft_exec(&(*ast)->left);
	data_singleton()->jobc.process.fdin = STDIN;
	data->jobc.process.command = NULL;
	btree_delone(ast, &ast_free);
	return (0);
}
