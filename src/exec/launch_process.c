/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:20:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 15:23:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		launch_process(t_process *p)
{
	t_exec	*exec;
	int		pid;

	exec = &data_singleton()->exec;
	if (p->attributes & PROCESS_UNKNOWN)
	{
		ft_dprintf(2, "{red}%s: command not found: %s{eoc}\n", SHELL_NAME, p->av[0]);
		set_exitstatus(127);
		return (1);
	}
	else if (p->attributes & PROCESS_BUILTIN && p->fdout == STDOUT)
		set_exitstatus((*p->execf)(p->path, p->av, data_singleton()->env));
	else
	{
		DG("process is to be forked, fdout=%i, attr=%b", p->fdout, p->attributes);
		if (p->attributes & (PROCESS_BINARY | PROCESS_SCRIPT)
				&& access(p->path, X_OK) == -1)
		{
			ft_dprintf(2, "{red}%s: permission denied: %s{eoc}\n", SHELL_NAME, p->av[0]);
			return (-1);
		}
		pid = fork();
		if (pid == 0)
		{
			process_setgroup(p);
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			signal(SIGTSTP, sigtstp_handler);
			signal(SIGTTIN, SIG_DFL);
			signal(SIGTTOU, SIG_DFL);
			signal(SIGCHLD, SIG_DFL);
			process_redirect(p);
			(*p->execf)(p->path, p->av, data_singleton()->env);
			exit(42);
		}
		else if (pid > 0)
			p->pid = pid;
		else if (pid == -1)
			perror("fork");
	}
	return (0);
}
