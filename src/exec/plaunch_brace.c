/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_brace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:09:30 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 23:57:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_brace(t_process *p)
{
	pid_t	pid;

	DG("plaunch_brace");
	if (IS_PIPESINGLE(*p))
	{
		if (process_redirect(p))
		{
			DG("BRACE_GROUP redirection failed");
			set_exitstatus(1, 1);
			return (0);
		}
		ft_exec(&p->data.brace.content);
		return (0);
	}
	pid = fork();
	if (pid == 0)
	{
		DG("fork!");
		data_singleton()->opts &= ~SH_INTERACTIVE;
		/* data_singleton()->opts &= ~SH_OPTS_JOBC; */
		if (process_redirect(p))
			exit (1);
		process_setgroup(p, 0);
		process_setsig();
		exec_reset();
		ft_exec(&p->data.brace.content);
		exit(ft_atoi(ft_getenv(data_singleton()->env, "?")));
	}
	else if (pid > 0)
		return (pid);
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (0);
}
