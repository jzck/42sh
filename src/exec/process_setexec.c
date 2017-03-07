/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 16:39:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	p->data.cmd.path = NULL;
	p->data.cmd.execf = NULL;
	/* if ((p->execf = is_function(p))) */
	/* 	p->type = PROCESS_FUNCTION; */
	if ((p->data.cmd.execf = is_builtin(p)))
		p->type = PROCESS_BUILTIN;
	else if (ft_strchr(p->av[0], '/'))
	{
		p->type = PROCESS_FILE;
		p->data.cmd.execf = &execve;
		p->data.cmd.path = ft_strdup(p->av[0]);
		stat(p->data.cmd.path, &p->data.cmd.stat);
	}
	else
	{
		p->type = PROCESS_FILE;
		if (ft_hash(p))
		{
			p->data.cmd.execf = &execve;
			lstat(p->data.cmd.path, p->data.cmd.stat);
		}
	}
	return (0);
}
