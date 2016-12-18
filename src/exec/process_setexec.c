/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 15:19:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	if ((p->execf = is_builtin(p)))
	{
		DG("process is a builtin");
		p->attributes |= PROCESS_BUILTIN;
	}
	else if (ft_strchr(p->argv[0], '/'))
	{
		DG("process is a script");
		p->execf = &execve;
		p->attributes |= PROCESS_SCRIPT;
		p->path = ft_strdup(p->argv[0]);
	}
	else if ((p->path = ft_findexec(ft_getenv(
						data_singleton()->env, "PATH"), p->argv[0])))
	{
		DG("process is binary");
		p->execf = &execve;
		p->attributes |= PROCESS_BINARY;
	}
	else
	{
		DG("process is '%s' unknown type", p->argv[0]);
		p->execf = NULL;
		p->attributes |= PROCESS_UNKNOWN;
		return (1);
	}
	return (0);
}
