/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 19:02:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		mark_process_status(pid_t pid, int status)
{
	t_list		*plist;
	t_process	*p;

	if (pid > 1)
	{
		DG("MPS pid=%i,s=%i", pid, status);
		if ((plist = job_getprocess(pid)))
		{
			p = plist->content;
			p->status = status;
			if (WIFSTOPPED(status))
			{
				p->attributes &= ~PROCESS_STATE_MASK;
				p->attributes |= PROCESS_SUSPENDED;
			}
			else
			{
				p->attributes &= ~PROCESS_STATE_MASK;
				p->attributes |= PROCESS_COMPLETED;
				if (WIFSIGNALED(status))
					ft_printf("{mag}%d: Terminated by signal %d.\n{eoc}",
							(int)pid, WTERMSIG(status));
			}
			return (0);
		}
		ft_dprintf(2, "No child process %d.\n", pid);
	}
	return (-1);
}
