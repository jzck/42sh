/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/06 12:26:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	p->path = NULL;
	if ((p->execf = is_builtin(p)))
		p->attrs |= PROCESS_BUILTIN;
	else if (ft_strchr(p->av[0], '/'))
	{
		p->execf = &execve;
		p->attrs |= PROCESS_SCRIPT;
		p->path = ft_strdup(p->av[0]);
	}
	else if (ft_hash(p))
	{
		p->execf = &execve;
		p->attrs |= PROCESS_BINARY;
	}
	else
	{
		p->execf = NULL;
		p->attrs |= PROCESS_UNKNOWN;
		return (1);
	}
	return (0);
}
