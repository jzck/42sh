/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_great.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/05 12:13:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_great(t_btree **ast, t_data *data)
{
	t_astnode	*node;
	int			fd;

	node = (*ast)->item;
	fd = open(node->data.redir.word.word, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	data->exec.fdout = fd;
	ft_exec(&(*ast)->left, data);
	data->exec.fdout = STDOUT;
	btree_delone(ast, &ast_free);
	return (0);
}
