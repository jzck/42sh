/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 20:40:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_reset_job(t_job *job)
{
	job->id = 0;
	job->pgid = 0;
	job->attrs = JOB_NOTIFIED;
	job->first_process = NULL;
	return (0);
}

int			exec_reset(void)
{
	t_exec	*exec;
	t_jobc	*jobc;
	int		i;

	exec = &data_singleton()->exec;
	jobc = &data_singleton()->jobc;
	i = -1;
	while (++i < 10)
		exec->fd_save[i] = fcntl(i, F_DUPFD_CLOEXEC, 10);
	exec->op_stack = NULL;
	exec->fdin = STDIN;
	exec->attrs = 0;
	exec_reset_job(&exec->job);
	tcgetattr(STDIN, &exec->job.tmodes);
	jobc->first_job = NULL;
	jobc->current_id = 1;
	return (0);
}
