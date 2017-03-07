/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_while.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:33:53 by ariard            #+#    #+#             */
/*   Updated: 2017/03/07 16:41:50 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_while(t_btree **ast)
{
	int ret;
	DG("exec while condition");
	ft_exec(&(*ast)->left);
	DG("ret :[%s]", ft_getenv(data_singleton()->env, "?"));
	while (!(ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0")))
	{
		DG("in the while");
		ft_exec(&(*ast)->right);
	ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&(*ast)->left);
	}
	exit(ret);
	return (0);
}

static int		do_while(t_process *p)
{
	int		ret;
	return (ret);
}

int				launch_while(t_process *p)
{
	pid_t	pid;

	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		pid = fork();
		if (pid == 0)
			exit(do_while(p));
		else if (pid > 0)
		{
			p->pid = pid;
			process_setgroup(p, pid);
			return (0);
		}
	}
	else
		do_while(p);
	return (1);
}
