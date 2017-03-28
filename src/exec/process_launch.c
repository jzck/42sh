/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/28 20:29:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_fork(t_process *p)
{
	pid_t		pid;

	if ((pid = fork()) == -1)
		exit(SH_ERR("fork(): %s", strerror(errno)));
	else if (pid != 0)
		return (pid);
	if (!p)
		return (0);
	exec_destroy(&data_singleton()->exec);
	jobc_destroy(&data_singleton()->jobc);
	if ((pid = 1) && process_redirect(p) == 0)
	{
		shell_fds_push();
		process_setgroup(p, 0);
		process_setsig();
		data_singleton()->opts &= ~(SH_INTERACTIVE | SH_OPTS_JOBC);
		pid = p->map.launch(p);
	}
	shell_fds_destroy();
	exit(pid);
}

int		process_launch(t_process *p)
{
	p->state = PROCESS_RUNNING;
	if (!IS_PIPESINGLE(*p) || p->type == PROCESS_FILE
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
		shell_fds_push();
		p->map.launch(p);
		shell_fds_pop();
	}
	shell_fds_reset();
	shell_sig_reset();
	process_free(p, 0);
	return (0);
}
