/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 02:54:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_fork(t_process *p)
{
	pid_t		pid;

	if ((pid = fork()) == -1)
		exit(SH_ERR("fork(): %s", strerror(errno)));
	else if (pid)
		return (pid);
	if (!p)
		return (pid);
	if (process_redirect(p))
		exit(1);
	process_setgroup(p, 0);
	process_setsig();
	exec_destroy(&data_singleton()->exec);
	exec_init(&data_singleton()->exec);
	data_singleton()->opts &= ~SH_INTERACTIVE;
	data_singleton()->opts &= ~SH_OPTS_JOBC;
	exit(p->map.launch(p));
}

int		process_launch(t_process *p)
{
	p->state = PROCESS_RUNNING;
	if (!IS_PIPESINGLE(*p)
			|| p->type == PROCESS_FILE
			|| p->type == PROCESS_SUBSHELL)
	{
		p->pid = process_fork(p);
		process_setgroup(p, p->pid);
		if (p->fdin != STDIN)
			close(p->fdin);
		if (p->fdout != STDOUT)
			close(p->fdout);
		return (1);
	}
	if (process_redirect(p))
		set_exitstatus(1, 1);
	else
	{
		exec_pushfds();
		p->map.launch(p);
		exec_popfds();
		shell_resetfds();
		shell_resetsig();
	}
	process_free(p, 0);
	return (0);
}
