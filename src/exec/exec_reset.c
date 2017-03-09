/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/09 15:22:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_reset(void)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	exec->fd_save[0] = fcntl(STDIN, F_DUPFD_CLOEXEC);
	exec->fd_save[1] = fcntl(STDOUT, F_DUPFD_CLOEXEC);
	exec->fd_save[2] = fcntl(STDERR, F_DUPFD_CLOEXEC);
	exec->op_stack = NULL;
	exec->fdin = STDIN;
	exec->attrs = 0;
	exec->job.id = 0;
	exec->job.pgid = 0;
	exec->job.attrs = 0;
	exec->job.first_process = NULL;
	return (0);
}
