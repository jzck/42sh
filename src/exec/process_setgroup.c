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

int		process_setgroup(t_process *p)
{
	t_job	*job;

	job = data_singleton()->exec.job;
	pid = getpid();
	if (job->pgid == 0)
		job->pgid = pid;
	setpgid(pid, job->pgid);
	if (job->foreground)
		tcsetpgrp(STDIN_FILENO, job->pgid);
}
