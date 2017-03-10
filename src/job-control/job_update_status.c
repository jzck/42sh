/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_update_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:56:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 12:41:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_update_status(void)
{
	int		status;
	pid_t	pid;

	do
	{
		pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG);
		DG("pid=[%d]", pid);
	}
	while (pid > 1 && !mark_process_status(pid, status));
}
