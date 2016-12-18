/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_job_notification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:01:19 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:49:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		do_job_notification(void)
{
	t_job		*j;
	t_list		*jlist;
	t_jobc		*jobc;
	int			ret;

	ret = 0;
	job_update_status();
	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	while (jlist)
	{
		j = jlist->content;
		DG("checking job [%i]", j->id);
		if (job_is_completed(j))
		{
			ret = 1;
			job_notify_change(j, 0);
			job_remove(j->id);
		}
		else if (job_is_stopped(j) && !(j->attributes & JOB_NOTIFIED))
		{
			ret = 1;
			job_notify_change(j, 8);
			j->attributes &= JOB_NOTIFIED;
		}
		jlist = jlist->next;
	}
	return (ret);
}
