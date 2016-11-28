/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_great.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 18:35:15 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_great(t_btree *ast, t_data *data)
{
	t_astnode	*node;
	int			fd;

	node = ast->item;
	fd = open(node->u_data.redir.u_word.word, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	data->fdout = fd;

	ft_exec(ast->left, data);

	data->fdout = STDOUT;
	return (0);
}
