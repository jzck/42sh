/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:15:22 by jhalford         ###   ########.fr       */
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
	data->exec.process.fdout = fds[PIPE_WRITE];
	ft_exec(&(*ast)->left);
	if (data->exec.process.fdout != STDOUT)
		close(data->exec.process.fdout);
	data->exec.process.fdout = STDOUT;
	data->exec.process.fdin = fds[PIPE_READ];
	ft_exec(&(*ast)->right);
	close(fds[PIPE_WRITE]);
	close(fds[PIPE_READ]);
	data->exec.process.fdin = STDIN;
	data->exec.process.fdout = STDOUT;
	btree_delone(ast, &ast_free);
	return (0);
}
