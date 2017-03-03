/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:44:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:44:42 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		add_new_job(t_job *job)
{
	t_jobc	*jobc;

	if (!job->first_process)
		return (1);
	jobc = &data_singleton()->jobc;
	job_update_id();
	job->id = jobc->current_id;
	job->pgid = ((t_process*)job->first_process->content)->pid;
	ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
	if (JOB_IS_FG(job->attrs))
		put_job_in_foreground(job, 0);
	else
	{
		job_notify_new(job);
		put_job_in_background(job, 0);
	}
	return (0);
}
