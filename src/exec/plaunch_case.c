/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:02:23 by wescande          #+#    #+#             */
/*   Updated: 2017/03/15 00:04:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static int		do_case(t_process *p)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	exec->attrs &= ~EXEC_CASE_BRANCH;
	exec->case_pattern = token_to_argv(p->data.d_case.list_word, 1);
/*	ft_exec(&p->data.d_if.condition);
	if (!(ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0")))
	{
		exec->attrs |= EXEC_IF_BRANCH;
		ft_exec(&p->data.d_if.content);
	}
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));*/
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
