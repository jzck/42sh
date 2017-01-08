/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 14:55:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		process_mark_status(pid_t pid, int status)
{
	t_process	*p;

	if (pid > 1)
	{
		if ((p = job_getprocess(pid)))
		{
			p->status = status;
			if (WIFSTOPPED(status))
			{
				DG("marking: pid=%i, status=%i (stopped)", pid, status);
				p->attributes |= PROCESS_STOPPED;
			}
			else
			{
				DG("marking: pid=%i, status=%i (completed)", pid, status);
				p->attributes |= PROCESS_COMPLETED;
				if (WIFSIGNALED(status))
					ft_printf("{mag}%d: Terminated by signal %d.\n{eoc}",
							(int) pid, WTERMSIG(p->status));
			}
			return(0);
		}
		ft_dprintf(2, "No child process %d.\n", pid);
		return(-1);
	}
	return(-1);
}
