/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_resetfds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:51:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/11 17:58:14 by jhalford         ###   ########.fr       */
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
		close(i++);
	dup2(exec->fd_save[0], STDIN);
	dup2(exec->fd_save[1], STDOUT);
	dup2(exec->fd_save[2], STDERR);
}
