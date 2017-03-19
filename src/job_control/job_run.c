/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:54:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 14:47:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_run(t_job *job, int foreground)
{
	mark_job_as_running(job);
	job_format(job, JOBS_OPTS_L);
	if (foreground)
		put_job_in_foreground(job, 1);
	else
		put_job_in_background(job, 1);
}
