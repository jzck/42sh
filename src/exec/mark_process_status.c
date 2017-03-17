/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/17 22:55:09 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mark_process_status(pid_t pid, int status)
{
	t_list		*plist;
	t_process	*p;

	if ((plist = job_getprocess(pid)))
	{
	DG("#######################");
		p = plist->content;
		p->status = status;
		if (WIFSTOPPED(status))
		{
	DG("#######################");
			p->attrs &= ~PROCESS_STATE_MASK;
			p->attrs |= PROCESS_SUSPENDED;
		}
		else
		{
	DG("#######################");
			p->attrs &= ~PROCESS_STATE_MASK;
			p->attrs |= PROCESS_COMPLETED;
			if (WIFSIGNALED(status) && DEBUG_MODE)
				ft_printf("{mag}%d: Terminated by signal %d.\n{eoc}",
						(int)pid, WTERMSIG(status));
		}
		return (0);
	}
	ft_dprintf(2, "{red}No child process %d.\n", pid);
	return (0);
}
