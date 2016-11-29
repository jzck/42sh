/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 19:19:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_pipe(t_btree *ast, t_data *data)
{
	int		fds[2];

	pipe(fds);
	ft_dprintf(2, "pipe %i->%i\n", fds[PIPE_WRITE], fds[PIPE_READ]);
	data->fdout = fds[PIPE_WRITE];

	ft_exec(ast->left, data);

	if (data->fdout != STDOUT)
		close(data->fdout);
	data->fdout = STDOUT;
	data->fdin = fds[PIPE_READ];

	ft_exec(ast->right, data);

	close(fds[PIPE_WRITE]);
	close(fds[PIPE_READ]);
	data->fdin = STDIN;
	data->fdout = STDOUT;
	return (0);
}
