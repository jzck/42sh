/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:49:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/02 17:32:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_wait(t_job *job)
{
	pid_t	pid;
	int		status;

	pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	while (!(process_mark_status(pid, status)
			|| job_is_stopped(job)
			|| job_is_completed(job)))
	{
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	}
	return(0);
}
