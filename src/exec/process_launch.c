/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 18:52:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				do_the_muther_forker(t_process *p)
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
	if (process_redirect(p))
		exit(1);
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
		/* set_exitstatus(p->map.launch(p), 1); */
		/* return (0); */
	}
	return (do_the_muther_forker(p));
}

int				process_launch(t_process *p)
{
	pid_t		pid;

	p->state = PROCESS_RUNNING;
	if (!(pid = do_the_fork_if_i_have_to(p)))
	{
		DG("NO_FORK");
		process_resetfds(p);
		process_free(p, 0);
		return (1);
	}
		DG("FORK");
	p->pid = pid;
	process_setgroup(p, pid);
	if (p->fdin != STDIN)
		close(p->fdin);
	if (p->fdout != STDOUT)
		close(p->fdout);
	return (0);
}
