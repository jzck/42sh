/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_if.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:26:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 02:04:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_if(t_process *p)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	exec->attrs &= ~EXEC_IF_BRANCH;
	ft_exec(&p->data.d_if.content);
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}

int				plaunch_if(t_process *p)
{
	pid_t	pid;

	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		pid = fork();
		if (pid == 0)
		{
			data_singleton()->opts &= ~SH_INTERACTIVE;
			data_singleton()->opts &= ~SH_OPTS_JOBC;
			process_setgroup(p, 0);
			process_setsig();
			if (process_redirect(p))
				exit (1);
			exec_reset();
			exit(do_if(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_if(p);
	return (0);
}
