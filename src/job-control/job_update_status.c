/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_update_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:56:11 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 15:09:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_update_status(void)
{
	int		status;
	pid_t	pid;

	DG("updating job status'");
	pid = waitpid (WAIT_ANY, &status, WUNTRACED|WNOHANG);
	while (!process_mark_status(pid, status))
		pid = waitpid (WAIT_ANY, &status, WUNTRACED|WNOHANG);
}
