/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_job_as_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:40:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 14:53:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	mark_job_as_running (t_job *j)
{
	t_list		*plist;
	t_process	*p;

	plist = j->first_process;
	while (plist)
	{
		p = plist->content;
		p->attributes &= ~PROCESS_STOPPED;
		plist = plist->next;
	}
	j->attributes &= ~JOB_NOTIFIED;
}
