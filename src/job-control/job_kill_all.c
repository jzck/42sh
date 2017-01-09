/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_kill_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 15:36:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 16:35:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_kill_all(void)
{
	t_jobc		*jobc;
	t_list		*jlist;
	t_job		*job;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	while (jlist)
	{
		job = jlist->content;
		kill(-job->pgid, SIGKILL);
		jlist = jlist->next;
	}
}
