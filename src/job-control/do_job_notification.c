/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_job_notification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:01:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 11:24:23 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (job_is_completed(j->id)
				|| (job_is_stopped(j->id) && !(j->attrs & JOB_NOTIFIED)))
		{
			ret = 1;
			job_notify_change(j->id);
			if (job_is_completed(j->id))
			{
				jlist = jlist->next;
				job_remove(j->id);
				continue ;
			}
			else
				j->attrs |= JOB_NOTIFIED;
		}
		jlist = jlist->next;
	}
	return (ret);
}
