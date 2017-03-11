/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:54:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/11 16:05:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_addprocess(t_process *p)
{
	t_jobc	*jobc;
	t_job	*job;

	jobc = &data_singleton()->jobc;
	job = &data_singleton()->exec.job;
	if (IS_PIPESTART(*p))
	{
		job_update_id();
		job->id = jobc->current_id;
		/* job->pgid = SH_HAS_JOBC(data_singleton()->opts) ? p->pid : getpid(); */
		job->pgid = p->pid;
		ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
	}
	DG("adding pid=[%i] to pgid=[%i]", p->pid, job->pgid);
	job = jobc->first_job->content;
	ft_lsteadd(&job->first_process, ft_lstnew(p, sizeof(*p)));
	/* DG("[BG:%i]", JOB_IS_BG(job->attrs)); */
	if (JOB_IS_BG(job->attrs) && IS_PIPEEND(*p))
	{
		job_notify_new(job);
	}
	return (0);
}
