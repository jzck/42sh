/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:49:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 19:42:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_wait(int id)
{
	pid_t	pid;
	int		status;

	DG("job wait [%i]", id);
	do
		pid = waitpid(WAIT_ANY, &status, WUNTRACED);
	while (!mark_process_status(pid, status)
			&& !job_is_stopped(id)
			&& !job_is_completed(id));
	return (0);
}
