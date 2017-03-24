/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_mark_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 17:28:45 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		mark_process_status(pid_t pid, int status)
{
	t_list		*plist;
	t_process	*p;
	int			signo;

	if ((plist = job_getprocess(pid)))
	{
		p = plist->content;
		p->status = status;
		if (WIFSTOPPED(status))
			p->state = PROCESS_SUSPENDED;
		else
		{
			p->state = PROCESS_COMPLETED;
			if (WIFSIGNALED(status) && (signo = WTERMSIG(status)))
			{
				if (signo != SIGPIPE && signo != SIGINT)
					ft_dprintf(2, "%s\n", strsignal(signo));
			}
		}
		return (0);
	}
	SH_ERR("No child process %d", pid);
	return (1);
}
