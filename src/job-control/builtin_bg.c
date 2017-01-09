/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:54:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 16:57:20 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "job_control.h"

int		builtin_bg(const char *path, char *const av[], char *const envp[])
{
	t_jobc	*jobc;
	t_job	*job;
	int		rank[2];

	(void)path;
	(void)envp;
	(void)av;
	jobc = &data_singleton()->jobc;
	job = jobc->first_job->content;
	job_getrank(&rank);
	if (job)
	{
		mark_job_as_running(job);
		job_format(job, rank, JOBS_OPTS_L);
		put_job_in_background(job, 1);
	}
	return (0);
}
