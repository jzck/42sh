/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:49:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 13:44:17 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_wait(int id)
{
	pid_t	pid;
	int		status;

	DG("waiting for [%i]", id);
	if (job_is_stopped(id))
		return (0);
	job_update_status();
	pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	while (!process_mark_status(pid, status)
			&& !job_is_completed(id)
			&& !job_is_stopped(id))
	{
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	}
	return (0);
}
