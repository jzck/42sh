/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:04:42 by wescande          #+#    #+#             */
/*   Updated: 2017/03/08 15:08:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_until(t_process *p)
{
	int		ret;

	ft_exec(&p->data.d_until.condition);
	ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
	while (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0"))
	{
		ft_exec(&p->data.d_until.content);
		ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&p->data.d_until.condition);
	}
	return (ret);
}

int				launch_until(t_process *p)
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
			exit(do_until(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_until(p);
	return (0);
}
