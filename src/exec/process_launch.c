/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/17 20:31:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int		do_the_muther_forker(t_process *p)
{
	pid_t		pid;

	if (IS_PIPESINGLE(*p) && p->type != PROCESS_FILE && p->type != PROCESS_SUBSHELL)
	{
		if (process_redirect(p))
		{
			set_exitstatus(1, 1);
			return (0);
		}
		set_exitstatus(p->map.launch(p), 1);
		return (0);
	}
	if ((pid = fork()) == -1)
	{
		ft_dprintf(3, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
		exit(1);
	}
	else if (pid)
		return (pid);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGCHLD, SIG_DFL);
	data_singleton()->opts &= ~SH_INTERACTIVE;
	data_singleton()->opts &= ~SH_OPTS_JOBC;
	if (process_redirect(p))
		exit (1);
	process_setgroup(p, 0);
	process_setsig();
	exec_reset();
	exit(p->map.launch(p));
}

int		process_launch(t_process *p)
{
	pid_t		pid;

	DG("p->type=%i", p->type);
	p->attrs &= ~PROCESS_STATE_MASK;
	p->attrs |= PROCESS_RUNNING;
	if (!(pid = do_the_muther_forker(p)))
	{
		DG("launcher did not fork!");
		process_resetfds(p);
		return (1);
	}
	DG("launcher forked!");
	p->pid = pid;
	process_setgroup(p, pid);
	if (p->fdin != STDIN)
		close(p->fdin);
	if (p->fdout != STDOUT)
		close(p->fdout);
	return (0);
}
