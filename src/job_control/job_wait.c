/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 11:49:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:31:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_wait(int id)
{
	pid_t	pid;
	t_job	*j;
	t_list	*jlist;
	t_jobc	*jobc;
	int		status;

	jobc = &data_singleton()->jobc;
	if (!(jlist = ft_lst_find(jobc->first_job, &id, job_cmp_id)))
		return (-1);
	j = jlist->content;
	while (1)
	{
		if ((pid = waitpid(-j->pgid, &status, WUNTRACED)) == -1
				&& errno != ECHILD)
			ft_dprintf(2, "{red}%s: waitpid error errno=%i{eoc}\n",
					SHELL_NAME, errno);
		DG("wait trigger pid=%i", pid);
		if (pid <= 1 || mark_process_status(pid, status)
			|| job_is_stopped(j)
			|| job_is_completed(j))
			break ;
	}
	return (0);
}
