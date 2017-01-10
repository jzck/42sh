/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 13:17:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	if ((p->execf = is_builtin(p)))
	{
		p->attributes |= PROCESS_BUILTIN;
	}
	else if (ft_strchr(p->av[0], '/'))
	{
		p->execf = &execve;
		p->attributes |= PROCESS_SCRIPT;
		p->path = ft_strdup(p->av[0]);
	}
	else if ((p->path = ft_findexec(ft_getenv(
						data_singleton()->env, "PATH"), p->av[0])))
	{
		p->execf = &execve;
		p->attributes |= PROCESS_BINARY;
	}
	else
	{
		p->execf = NULL;
		p->attributes |= PROCESS_UNKNOWN;
		return (1);
	}
	return (0);
}
