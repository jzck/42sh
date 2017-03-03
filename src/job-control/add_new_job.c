/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:44:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:49:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		add_new_job(t_job *job)
{
	t_jobc	*jobc;

	DG("adding new job");
	if (!job->first_process)
		return (1);
	jobc = &data_singleton()->jobc;
	job_update_id();
	job->id = jobc->current_id;
	job->pgid = ((t_process*)job->first_process->content)->pid;
	ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
	job = jobc->first_job->content;
	return (0);
}
