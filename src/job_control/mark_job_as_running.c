/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_job_as_running.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:40:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 11:33:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mark_job_as_running(t_job *j)
{
	t_list		*plist;
	t_process	*p;

	plist = j->first_process;
	while (plist)
	{
		p = plist->content;
		if (p->state == PROCESS_SUSPENDED)
			p->state = PROCESS_CONTINUED;
		plist = plist->next;
	}
	j->attrs &= ~JOB_NOTIFIED;
}
