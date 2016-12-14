/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 13:02:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		process_mark_status(pid_t pid, int status)
{
	t_process	*p;
	t_jobc		*jobc;

	jobc = &data_singleton()->jobc;
	if (pid > 0)
	{
		if ((p = job_getprocess(pid)))
		{
			p->status = status;
			if (WIFSTOPPED(status))
				p->attributes &= PROCESS_STOPPED;
			else
			{
				p->attributes &= PROCESS_COMPLETED;
				if (WIFSIGNALED(status))
					ft_printf("%d: Terminated by signal %d.\n",
							(int) pid, WTERMSIG (p->status));
			}
			return(0);
		}
		ft_dprintf(STDERR, "No child process %d.\n", pid);
		return(-1);
	}
	else
		return(-1);
}
