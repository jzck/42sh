/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_resetfds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:51:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 20:54:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_resetfds(t_process *p)
{
	t_exec	*exec;
	int		i;

	(void)p;
	exec = &data_singleton()->exec;
	i = 0;
	while (i < 10)
	{
		/* if (i!=3) //JACK SOME PB HERE  on close la sortie debug en forcant le close sur tous les fd... ne risque-t-on pas autre chose ??!!! */
		/* { */
			close(i++);
		/* } */
		/* else */
		/* 	i++; */
	}
	if (exec->fd_save[0] != -1)
		dup2(exec->fd_save[0], STDIN);
	if (exec->fd_save[1] != -1)
		dup2(exec->fd_save[1], STDOUT);
	if (exec->fd_save[2] != -1)
		dup2(exec->fd_save[2], STDERR);
}
