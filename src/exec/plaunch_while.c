/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:20:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/16 18:44:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		do_while(t_process *p)
{
	int		ret;

	ft_exec(&p->data.d_while.condition);
	ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
	while (!(ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0")))
	{
		ft_exec(&p->data.d_while.content);
		ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&p->data.d_while.condition);
	}
	return (ret);
}

int				plaunch_while(t_process *p)
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
			exit(do_while(p));
		}
		else if (pid > 0)
			return (pid);
	}
	else
		do_while(p);
	return (0);
}
