/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:48:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 16:51:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		launch_builtin(t_process *p)
{
	pid_t	pid;

	if (IS_PIPESINGLE(*p))
	{
		if (process_redirect(p))
			return (0);
		set_exitstatus((*p->data.cmd.execf)(p->data.cmd.path, p->data.cmd.av, data_singleton()->env), 1);
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		process_setgroup(p, 0);
		process_setsig();
		if (process_redirect(p))
			exit (1);
		exit((*p->data.cmd.execf)(p->data.cmd.path, p->data.cmd.av, data_singleton()->env));
	}
	else if (pid > 0)
		return (pid);
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (0);
}
