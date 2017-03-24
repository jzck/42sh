/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_hup_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:37:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 15:40:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_hup_all(void)
{
	t_jobc		*jobc;
	t_list		*jlist;
	t_job		*job;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	if (!SH_HAS_JOBC(data_singleton()->opts))
		return ;
	while (jlist)
	{
		job = jlist->content;
		DG("gonna SIGHUP %i", job->pgid);
		builtin_jobs(NULL, NULL, NULL);
		if (job->pgid != 1)
			kill(-job->pgid, SIGHUP);
		DG("after SIGHUP %i", job->pgid);
		jlist = jlist->next;
	}
}
