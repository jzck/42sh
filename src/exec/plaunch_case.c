/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 01:10:32 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_case(t_process *p)
{
	t_exec	*exec;

	DG("exec case");
	exec = &data_singleton()->exec;
	exec->attrs &= ~EXEC_CASE_BRANCH;
	exec->case_pattern = token_to_argv(p->data.d_case.token, 1);
	ft_exec(&p->data.d_if.content);
	return (0);
}

int				plaunch_case(t_process *p)
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
			exit(do_case(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_case(p);
	return (0);
}
