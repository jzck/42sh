/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:48:10 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:48:11 by jhalford         ###   ########.fr       */
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
	setpgid(pid, job->pgid);
	if (JOB_IS_FG(job->attributes))
		tcsetpgrp(STDIN_FILENO, job->pgid);
	return (0);
}
