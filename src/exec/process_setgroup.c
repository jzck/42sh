/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:48:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 14:45:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"
#include "exec.h"

int		process_setgroup(t_process *p, pid_t pid)
{
	t_job	*j;

	(void)p;
	if (!SHELL_HAS_JOBC(data_singleton()->opts))
		return (0);
	j = &data_singleton()->exec.job;
	if (!j->pgid)
		j->pgid = pid ? pid : getpid();
	setpgid(pid, j->pgid);
	if (pid == 0 && JOB_IS_FG(j->attributes))
		tcsetpgrp(STDIN, j->pgid);
	return (0);
}
