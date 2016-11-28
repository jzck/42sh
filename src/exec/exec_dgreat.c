/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_dgreat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:15:13 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 18:36:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_dgreat(t_btree *ast, t_data *data)
{
	t_astnode	*node;
	int			fd;

	node = ast->item;
	fd = open(node->u_data.redir.u_word.word, O_WRONLY | O_APPEND | O_CREAT, 0644);
	data->fdout = fd;

	ft_exec(ast->left, data);

	data->fdout = STDOUT;
	return (0);
}
