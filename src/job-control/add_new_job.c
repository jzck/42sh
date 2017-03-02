/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:44:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/02 21:04:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		add_new_job(t_list	*first_process, int foreground)
{
	t_jobc	*jobc;
	t_job	job;

	if (!first_process)
		return (1);
	jobc = &data_singleton()->jobc;
	job_update_id();
	job->id = jobc->current_id;
	job->pgid = ((t_process*)first_process->content)->pid;
	job->attrs = foreground ? 0 : JOB_BG;
	job->first_process = first_process;
	ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
	if (JOB_IS_FG(job->attrs))
		put_job_in_foreground(job, 0);
	else
		job_notify_new(job);
		put_job_in_background(job, 0);
	return (0);
}
