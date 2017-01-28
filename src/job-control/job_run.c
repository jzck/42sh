/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:54:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 14:37:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_run(t_job *job, int foreground)
{
	int		rank[2];

	job_getrank(&rank);
	mark_job_as_running(job);
	job_format(job, rank, JOBS_OPTS_L);
	foreground ? put_job_in_foreground(job, 1) : put_job_in_background(job, 1);
}
