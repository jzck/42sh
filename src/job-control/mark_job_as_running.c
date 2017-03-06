/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_job_as_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:40:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/06 12:30:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	mark_job_as_running(t_job *j)
{
	t_list		*plist;
	t_process	*p;

	plist = j->first_process;
	while (plist)
	{
		p = plist->content;
		if (p->attrs & PROCESS_SUSPENDED)
		{
			p->attrs &= ~PROCESS_STATE_MASK;
			p->attrs |= PROCESS_CONTINUED;
		}
		plist = plist->next;
	}
	j->attrs &= ~JOB_NOTIFIED;
}
