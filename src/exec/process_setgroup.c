/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:48:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 15:58:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"
#include "exec.h"

int		process_setgroup(t_process *p)
{
	t_job	*job;
	int		pid;

	(void)p;
	job = &data_singleton()->exec.job;
	pid = getpid();
	if (job->pgid == 0)
		job->pgid = pid;
	if (setpgid(pid, job->pgid))
		DG("setpgid(%i, %i) failed", pid, job->pgid);
	if (JOB_IS_FG(job->attributes))
	{
		signal(SIGTTOU, SIG_IGN);
		tcsetpgrp(STDIN, job->pgid);
		signal(SIGTTOU, SIG_DFL);
	}
	return (0);
}
