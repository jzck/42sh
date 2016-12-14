/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:20:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:50:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		launch_process(t_process *p)
{
	t_exec	*exec;
	int		pid;

	exec = &data_singleton()->exec;
	if (p->attributes & PROCESS_UNKNOWN)
		ft_dprintf(2, "%s: command not found: %s\n", SHELL_NAME, p->argv[0]);
	else if (p->attributes & PROCESS_BUILTIN && p->fdout != STDOUT)
		set_exitstatus((*p->execf)(p->path, p->argv, data_singleton()->env));
	else
	{
		if (p->attributes & (PROCESS_BINARY | PROCESS_SCRIPT)
				&& access(p->path, X_OK) == -1)
		{
			ft_dprintf(2, "%s: permission denied: %s\n", SHELL_NAME, p->argv[0]);
			return (-1);
		}
		pid = fork();
		if (pid == 0)
		{
			process_setgroup(p);
			process_redirect(p);
			(*p->execf)(p->path, p->argv, data_singleton()->env);
			exit(42);
		}
		else if (pid > 0)
			p->pid = pid;
		else if (pid == -1)
			perror("fork");
		if (p->fdout == STDOUT)
		{
			waitpid(pid, &p->status, 0);
			set_exitstatus(p->status);
		}
	}
	return (0);
}
