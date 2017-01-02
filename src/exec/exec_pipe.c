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
	t_process	*p;

	data = data_singleton();
	p = &data_singleton()->exec.process;
	pipe(fds);
	DG("pipe %i->%i", fds[PIPE_WRITE], fds[PIPE_READ]);
	p->fdout = fds[PIPE_WRITE];
	if (!IS_PIPEEND(p->attributes))
		p->attributes |= PROCESS_PIPESTART;
	else
		p->attributes &= ~PROCESS_PIPESTART;
	p->attributes &= ~PROCESS_PIPEEND;

	ft_exec(&(*ast)->left);
	if (p->fdout != STDOUT)
		close(p->fdout);
	p->fdout = STDOUT;
	p->fdin = fds[PIPE_READ];
	p->attributes &= ~PROCESS_PIPESTART;
	p->attributes |= PROCESS_PIPEEND;

	ft_exec(&(*ast)->right);
	/* close(fds[PIPE_WRITE]); */
	/* close(fds[PIPE_READ]); */
	p->fdin = STDIN;
	p->fdout = STDOUT;
	p->attributes |= PROCESS_PIPESTART;
	p->attributes &= ~PROCESS_PIPEEND;
	btree_delone(ast, &ast_free);
	return (0);
}
