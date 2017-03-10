/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:48:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 16:51:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell.h"

int		process_setgroup(t_process *p, pid_t pid)
{
	t_job	*j;
	t_data	*data;

	(void)p;
	data = data_singleton();
	if (!SH_HAS_JOBC(data->opts))
		return (0);
	j = &data->exec.job;
	/* DG("setpgid(%i, %i)", pid, j->pgid); */
	setpgid(pid, j->pgid);
	if (pid == 0 && JOB_IS_FG(j->attrs))
		tcsetpgrp(STDIN, j->pgid);
	return (0);
}
