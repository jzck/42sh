/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_setexec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:07:10 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 12:54:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		process_setexec(t_process *p)
{
	t_btree		*func;
	p->data.cmd.path = NULL;
	p->data.cmd.execf = NULL;
	p->data.cmd.stat = ft_memalloc(sizeof(struct stat));
	DG("gonna setexec av[0]=[%s]", p->data.cmd.av[0]);
	if ((func = is_function(p)))
	{
		p->data.subshell.content = func;
		p->type = PROCESS_FUNCTION;
	}
	else if ((p->data.cmd.execf = is_builtin(p)))
		p->type = PROCESS_BUILTIN;
	else if (ft_strchr(p->data.cmd.av[0], '/'))
	{
		p->type = PROCESS_FILE;
		p->data.cmd.execf = &execve;
		p->data.cmd.path = ft_strdup(p->data.cmd.av[0]);
		if (stat(p->data.cmd.path, p->data.cmd.stat) == -1)
			ft_memdel((void**)&p->data.cmd.stat);
	}
	else
	{
		p->type = PROCESS_FILE;
		if (ft_hash(p))
		{
			p->data.cmd.execf = &execve;
			DG("found hash at [%s]", p->data.cmd.path);
			if (stat(p->data.cmd.path, p->data.cmd.stat) == -1)
			{
				ft_memdel((void**)&p->data.cmd.stat);
				ft_dprintf(2, "{red}%s: %s: unexpected stat (2) failure\n", SHELL_NAME, p->data.cmd.path);
			}
		}
	}
	return (0);
}
