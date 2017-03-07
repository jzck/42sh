/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 14:49:45 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	p->path = NULL;
	/* if ((p->execf = is_function(p))) */
	/* 	p->type = PROCESS_FUNCTION; */
	if ((p->data.cmd.execf = is_builtin(p)))
		p->type = PROCESS_BUILTIN;
	else if (ft_hash(p))
	{
		p->data.cmd.execf = &execve;
		p->type = PROCESS_FILE;
	}
	else if (ft_strchr(p->av[0], '/'))
	{
		p->data.cmd.execf = &execve;
		p->type = PROCESS_FILE;
		p->data.cmd.path = ft_strdup(p->av[0]);
	}
	else
	{
		p->execf = NULL;
		p->attrs |= PROCESS_UNKNOWN;
		return (1);
	}
	return (0);
}
