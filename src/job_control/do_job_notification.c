/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_job_notification.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:01:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 15:58:33 by jhalford         ###   ########.fr       */
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
		jlist = jlist->next;
		if (job_is_completed(j)
			|| (job_is_stopped(j) && !(j->attrs & JOB_NOTIFIED)))
		{
			ret = 1;
			job_format(j, JOBS_OPT_L);
			j->attrs |= JOB_NOTIFIED;
			job_remove(j->id);
		}
	}
	return (ret);
}
