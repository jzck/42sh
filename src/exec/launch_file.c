/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:53:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 17:35:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		launch_file(t_process *p)
{
	int		pid;

	/* DG("in file"); */
	pid = fork();
	if (pid == 0)
	{
		if (!p->data.cmd.path)
		{
			ft_dprintf(2, "{red}%s: command not found: %s{eoc}\n", SHELL_NAME, p->data.cmd.av[0]);
			exit(127);
		}
		else if (!p->data.cmd.stat)
		{
			ft_dprintf(2, "{red}%s: %s: no such file or directory\n", SHELL_NAME, p->data.cmd.av[0]);
			exit(127);
		}
		else if (S_ISDIR(p->data.cmd.stat->st_mode))
		{
			ft_dprintf(2, "{red}%s: %s: Is a directory{eoc}\n", SHELL_NAME, p->data.cmd.av[0]);
			exit(126);
		}
		else if (access(p->data.cmd.path, X_OK) == -1)
		{
			ft_dprintf(2, "{red}%s: permission denied: %s{eoc}\n", SHELL_NAME, p->data.cmd.av[0]);
			exit(126);
		}
		process_setgroup(p, 0);
		process_setsig();
		if (process_redirect(p))
			exit (1);
		exec_reset();
		(*p->data.cmd.execf)(p->data.cmd.path, p->data.cmd.av, data_singleton()->env);
		ft_dprintf(2, "{red}%s: internal execve error on %s{eoc}\n", SHELL_NAME, p->data.cmd.av[0]);
		exit(42);
	}
	else if (pid > 0)
		return (pid);
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (0);
}
