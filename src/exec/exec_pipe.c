/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 18:04:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_pipe(t_btree **ast)
{
	int			fds[2];
	t_data		*data;

	data = data_singleton();
	pipe(fds);
	DG("pipe %i->%i", fds[PIPE_WRITE], fds[PIPE_READ]);
	data->exec.fdout = fds[PIPE_WRITE];
	ft_exec(&(*ast)->left);
	if (data->exec.fdout != STDOUT)
		close(data->exec.fdout);
	data->exec.fdout = STDOUT;
	data->exec.fdin = fds[PIPE_READ];
	ft_exec(&(*ast)->right);
	close(fds[PIPE_WRITE]);
	close(fds[PIPE_READ]);
	data->exec.fdin = STDIN;
	data->exec.fdout = STDOUT;
	btree_delone(ast, &ast_free);
	return (0);
}
