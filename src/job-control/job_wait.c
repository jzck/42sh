/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:49:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 17:58:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_wait(int id)
{
	pid_t	pid;
	int		status;

	DG("job wait");
	if (job_is_stopped(id) || job_is_completed(id))
		return (0);
	DG("waitpid now");
	pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	DG("waitpid done");
	while (!process_mark_status(pid, status)
			&& !job_is_stopped(id)
			&& !job_is_completed(id))
	{
		DG("waitpid now");
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
		DG("waitpid done");
	}
	return (0);
}
