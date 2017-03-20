/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setgroup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:48:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 15:58:33 by gwojda           ###   ########.fr       */
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
	if (!SH_IS_INTERACTIVE(data_singleton()->opts))
		return (0);
	if (setpgid(pid, j->pgid) == -1)
		ft_dprintf(2, "{red}%s: internal setpgid() errno=%i{eoc}\n",
									SHELL_NAME, errno);
	if (pid == 0 && JOB_IS_FG(j->attrs))
		tcsetpgrp(STDIN, j->pgid);
	return (0);
}
