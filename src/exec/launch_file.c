/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:53:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 14:54:18 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		launch_file(t_process *p)
{
	int		pid;

	if (p->attrs & PROCESS_BUILTIN && IS_PIPESINGLE(*p))
	{
		if (process_redirect(p))
			return (1);
		set_exitstatus((*p->execf)(p->path, p->av, data_singleton()->env), 1);
		return (1);
	}
	p->attrs &= ~PROCESS_STATE_MASK;
	p->attrs |= PROCESS_RUNNING;
	if (p->attrs & (PROCESS_BINARY | PROCESS_SCRIPT)
			&& access(p->path, X_OK) == -1)
	{
		ft_dprintf(2, "{red}%s: permission denied: %s{eoc}\n", SHELL_NAME, p->av[0]);
		set_exitstatus(126, 1);
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		if (p->attrs & PROCESS_UNKNOWN)
		{
			ft_dprintf(2, "{red}%s: command not found: %s{eoc}\n", SHELL_NAME, p->av[0]);
			exit(127);
		}
		process_setgroup(p, 0);
		process_setsig();
		if (process_redirect(p))
			exit (1);
		if (p->attrs & PROCESS_BUILTIN)
			exit((*p->execf)(p->path, p->av, data_singleton()->env));
		(*p->execf)(p->path, p->av, data_singleton()->env);
		ft_dprintf(2, "{red}%s: internal execve error on %s{eoc}\n", SHELL_NAME, p->av[0]);
	}
	else if (pid > 0)
	{
		p->pid = pid;
		process_setgroup(p, pid);
		return (0);
	}
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (1);
}
