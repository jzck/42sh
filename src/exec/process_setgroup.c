/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:48:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/11 16:07:43 by jhalford         ###   ########.fr       */
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
	j = &data->exec.job;
	DG("setpgid(%i, %i)", pid, j->pgid);
	if (setpgid(pid, j->pgid) == -1)
		ft_dprintf(2, "{red}%s: internal setpgid() error{eoc}\n", SHELL_NAME);
	if (pid == 0 && JOB_IS_FG(j->attrs))
	{
		DG("I'm taking the terminal !");
		tcsetpgrp(STDIN, j->pgid);
	}
	return (0);
}
