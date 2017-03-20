/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:57:26 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		do_the_muther_forker(t_process *p)
{
	pid_t		pid;

	if ((pid = fork()) == -1)
	{
		ft_dprintf(3, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
		exit(1);
	}
	else if (pid)
		return (pid);
	if (!p)
		return (pid);
	DG("START OF FORK");
	if (process_redirect(p))
		exit (1);
	process_setgroup(p, 0);
	process_setsig();
	exec_reset();
	data_singleton()->opts &= ~SH_INTERACTIVE;
	data_singleton()->opts &= ~SH_OPTS_JOBC;
	exit(p->map.launch(p));
}

static int		do_the_fork_if_i_have_to(t_process *p)
{
	if (IS_PIPESINGLE(*p)
			&& p->type != PROCESS_FILE && p->type != PROCESS_SUBSHELL)
	{
		if (process_redirect(p))
		{
			set_exitstatus(1, 1);
			return (0);
		}
		return (p->map.launch(p));
	}
	return (do_the_muther_forker(p));
}

int		process_launch(t_process *p)
{
	pid_t		pid;

	DG("p->type=%i", p->type);
	p->state = PROCESS_RUNNING;
	if (!(pid = do_the_fork_if_i_have_to(p)))
	{
		DG("launcher did not fork!");
		process_resetfds(p);
		return (1);
	}
	DG("launcher forked! with : %d ", pid);
	p->pid = pid;
	process_setgroup(p, pid);
	if (p->fdin != STDIN)
		close(p->fdin);
	if (p->fdout != STDOUT)
		close(p->fdout);
	return (0);
}
