/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 10:40:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mark_process_status(pid_t pid, int status)
{
	t_list		*plist;
	t_process	*p;

	if ((plist = job_getprocess(pid)))
	{
		p = plist->content;
		p->status = status;
		if (WIFSTOPPED(status))
			p->state = PROCESS_SUSPENDED;
		else
		{
			p->state = PROCESS_COMPLETED;
			if (WIFSIGNALED(status))
				ft_dprintf(2, "%s\n", strsignal((WTERMSIG(status))));
		}
		return (0);
	}
	ft_dprintf(2, "{red}No child process %d.\n", pid);
	return (0);
}
