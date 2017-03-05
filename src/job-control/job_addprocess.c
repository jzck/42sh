/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:54:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 15:12:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

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
		job->pgid = p->pid;
		ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
	}
	job = jobc->first_job->content;
	if (p->pid > 0)
	{
		ft_lsteadd(&job->first_process, ft_lstnew(p, sizeof(*p)));
	}
	if (JOB_IS_BG(job->attrs) && IS_PIPEEND(*p))
		job_notify_new(job);
	return (0);
}
