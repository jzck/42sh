/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 16:09:02 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *std)
{
	ft_dprintf(2, "{red}%s: internal fcntl %s error errno=%i{eoc}\n",
							SHELL_NAME, std, errno);
}

int			exec_reset(void)
{
	t_exec	*exec;
	t_jobc	*jobc;

	exec = &data_singleton()->exec;
	jobc = &data_singleton()->jobc;
	if (errno != EBADF)
	{
		if ((exec->fd_save[0] = fcntl(STDIN, F_DUPFD_CLOEXEC, 10)) == -1)
			print_error("STDIN");
		if ((exec->fd_save[1] = fcntl(STDOUT, F_DUPFD_CLOEXEC, 10)) == -1)
			print_error("STDOUT");
		if ((exec->fd_save[2] = fcntl(STDERR, F_DUPFD_CLOEXEC, 10)) == -1)
			print_error("STDERR");
	}
	exec->op_stack = NULL;
	exec->fdin = STDIN;
	exec->attrs = 0;
	exec->job.id = 0;
	exec->job.pgid = 0;
	exec->job.attrs = JOB_NOTIFIED;
	exec->job.first_process = NULL;
	tcgetattr(STDIN, &exec->job.tmodes);
	jobc->first_job = NULL;
	jobc->current_id = 1;
	return (0);
}
