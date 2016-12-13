/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:54:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:06:57 by jhalford         ###   ########.fr       */
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
		job->id = current_id;
		job_update_id();
		ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
		if (job->foreground)
			put_job_in_foreground(job, 0);
		else
			put_job_in_background(job, 0);
	}
	if (p->fdout = STDOUT)
		job_notify_new(first_job);
	first_job = jobc->first_job->content;
	ft_lstadd(first_job->process, ft_lstnew(p, sizeof(*p)));
}
