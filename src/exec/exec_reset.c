/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 13:48:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_reset(void)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	/* exec->fd_save[0] = 1;//fcntl(STDIN, F_DUPFD_CLOEXEC); */
	/* exec->fd_save[1] = 1;//fcntl(STDOUT, F_DUPFD_CLOEXEC); */
	/* exec->fd_save[2] = 1;//fcntl(STDERR, F_DUPFD_CLOEXEC); */
	DG("check 0");
	if ((exec->fd_save[0] = fcntl(STDIN, F_DUPFD_CLOEXEC, 10)) == -1 && errno != EBADF)
		ft_dprintf(2, "{red}%s: internal fcntl STDIN error errno=%i %s{eoc}\n", SHELL_NAME, errno);
	DG("check 1");
	if ((exec->fd_save[1] = fcntl(STDOUT, F_DUPFD_CLOEXEC, 10)) == -1 && errno != EBADF)
		ft_dprintf(2, "{red}%s: internal fcntl STDOUT error errno=%i %s{eoc}\n", SHELL_NAME, errno);
	if ((exec->fd_save[2] = fcntl(STDERR, F_DUPFD_CLOEXEC, 10)) == -1 && errno != EBADF)
		ft_dprintf(2, "{red}%s: internal fcntl STDERR error errno=%i %s{eoc}\n", SHELL_NAME, errno);
	DG("saved [%i:%i:%i]", exec->fd_save[0], exec->fd_save[1], exec->fd_save[2]);
	exec->op_stack = NULL;
	exec->fdin = STDIN;
	exec->attrs = 0;
	exec->job.id = 0;
	exec->job.pgid = 0;
	exec->job.attrs = 0;
	exec->job.first_process = NULL;
	return (0);
}
