/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 14:42:01 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	p->data.cmd.path = NULL;
	if ((p->data.cmd.execf = is_builtin(p)))
		p->attrs |= PROCESS_BUILTIN;
	else if (ft_strchr(p->data.cmd.av[0], '/'))
	{
		p->data.cmd.execf = &execve;
		p->attrs |= PROCESS_SCRIPT;
		p->data.cmd.path = ft_strdup(p->data.cmd.av[0]);
	}
	else if (ft_hash(p))
	{
		p->data.cmd.execf = &execve;
		p->attrs |= PROCESS_BINARY;
	}
	else
	{
		p->data.cmd.execf = NULL;
		p->attrs |= PROCESS_UNKNOWN;
		return (1);
	}
	return (0);
}
