/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:11:44 by wescande          #+#    #+#             */
/*   Updated: 2017/03/13 23:59:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_subshell(t_process *p)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		data_singleton()->opts &= ~SH_INTERACTIVE;
		data_singleton()->opts &= ~SH_OPTS_JOBC;
		if (process_redirect(p))
			exit (1);
		process_setgroup(p, 0);
		process_setsig();
		exec_reset();
		ft_exec(&p->data.subshell.content);
		exit(ft_atoi(ft_getenv(data_singleton()->env, "?")));
	}
	else if (pid > 0)
		return (pid);
	return (0);
}
