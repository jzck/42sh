/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_update_status.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:56:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 14:53:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_update_status(void)
{
	int		status;
	pid_t	pid;

	do
	{
		if ((pid = waitpid(WAIT_ANY, &status, WUNTRACED | WNOHANG)) == -1
				&& errno != ECHILD)
			ft_dprintf(2, "{red}%s: waitpid error errno=%i{eoc}\n", SHELL_NAME, errno);
		DG("pid=[%d]", pid);
	}
	while (pid > 1 && !mark_process_status(pid, status));
}
