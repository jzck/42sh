/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:54:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 18:31:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_addprocess(t_process *p)
{
	t_jobc	*jobc;
	t_job	*job;

	jobc = &data_singleton()->jobc;
	job = &data_singleton()->exec.job;
	if (p->fdin == STDIN)
	{
		job_update_id();
		job->id = jobc->current_id;
		ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
		DG("added new job [%i], rank=%i:%i", job->id, jobc->rank[0], jobc->rank[1]);
	}
	job = jobc->first_job->content;
	ft_lstadd(&job->first_process, ft_lstnew(p, sizeof(*p)));
	if (JOB_IS_BG(job->attributes) && p->fdout == STDOUT)
		job_notify_new(job);
	DG("added process to first_job : %i", p->pid);
	return(0);
}
