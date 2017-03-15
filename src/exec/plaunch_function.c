/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:23:59 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 19:17:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_function(t_process *p)
{
	DG("do function");
	ft_exec(&p->data.function.content);
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}

int				plaunch_function(t_process *p)
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
			exit(do_function(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_function(p);
	return (0);
}
