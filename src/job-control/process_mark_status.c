/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/03 15:50:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		process_mark_status(pid_t pid, int status)
{
	t_list		*plist;
	t_process	*p;

	if (pid > 1)
	{
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
