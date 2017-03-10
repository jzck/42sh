/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 17:09:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mark_process_status(pid_t pid, int status)
{
	t_list		*plist;
	t_process	*p;

	DG("MPS pid=%i,s=%i", pid, status);
	if ((plist = job_getprocess(pid)))
	{
		p = plist->content;
		p->status = status;
		DG("marking pid=[%i], name=[%s]", p->pid, p->data.cmd.av[0]);
		if (WIFSTOPPED(status))
		{
			p->attrs &= ~PROCESS_STATE_MASK;
			p->attrs |= PROCESS_SUSPENDED;
		}
		else
		{
			p->attrs &= ~PROCESS_STATE_MASK;
			p->attrs |= PROCESS_COMPLETED;
			if (WIFSIGNALED(status))
				ft_printf("{mag}%d: Terminated by signal %d.\n{eoc}",
						(int)pid, WTERMSIG(status));
		}
		return (0);
	}
	ft_dprintf(2, "{red}No child process %d.\n", pid);
	return (0);
}
