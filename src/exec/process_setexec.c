/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 13:24:16 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_type type, t_process *p)
{
	p->path = NULL;
	if (type == TK_SUBSHELL)
	{
		p->execf = &execve;
		p->attributes |= PROCESS_SUBSHELL;
		p->path = ft_strdup(p->av[0]);
	}
	else if ((p->execf = is_builtin(p)))
	{
		p->attributes |= PROCESS_BUILTIN;
	}
	else if (ft_strchr(p->av[0], '/'))
	{
		p->execf = &execve;
		p->attributes |= PROCESS_SCRIPT;
		p->path = ft_strdup(p->av[0]);
	}
	else if (ft_hash(p))
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
