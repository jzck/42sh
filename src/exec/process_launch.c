/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/16 18:51:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_pipe(t_process *p)
{
	pid_t		pid;

	if (p->map.launch == plaunch_file)
		return (0);
	if (IS_PIPESINGLE(*p))
	{
/*		if (process_redirect(p))
		{
			set_exitstatus(1, 1);
			return (0);
		}
		set_exitstatus((*p->data.cmd.execf)(p->data.cmd.path, p->data.cmd.av, data_singleton()->env), 1);*/
		return (0);
	}
	pid = fork();
	if (!pid)
	{
		data_singleton()->opts &= ~SH_INTERACTIVE;
		data_singleton()->opts &= ~SH_OPTS_JOBC;
		if (process_redirect(p))
			exit (1);
		process_setgroup(p, 0);
		process_setsig();
		exec_reset();
	}
	return (pid); 
}

int		process_launch(t_process *p)
{
	pid_t		pid;
	/* pid_t		manage_pid; */

	DG("p->type=%i", p->type);
	p->attrs &= ~PROCESS_STATE_MASK;
	p->attrs |= PROCESS_RUNNING;
	/* if (!(manage_pid = check_pipe(p))) */
		if (!(pid = (*p->map.launch)(p)))
		{
			DG("launcher did not fork!");
			process_resetfds(p);
			return (1);
		}
	/* if (manage_pid) */
	/* 	pid = manage_pid; */
	DG("launcher forked!");
	p->pid = pid;
	process_setgroup(p, pid);
	if (p->fdin != STDIN)
		close(p->fdin);
	if (p->fdout != STDOUT)
		close(p->fdout);
	return (0);
}
