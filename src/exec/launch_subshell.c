/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:11:44 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 00:32:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_subshell(t_process *p)
{
	ft_exec(&p->data.subshell.content);
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}

int				launch_subshell(t_process *p)
{
	pid_t	pid;

	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		pid = fork();
		if (pid == 0)
		{
			data_singleton()->opts &= ~SH_INTERACTIVE;
			data_singleton()->opts &= ~SH_OPTS_JOBC;
			exit(do_subshell(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_subshell(p);
	return (0);
}
