/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_resetfds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:51:23 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 12:51:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_resetfds(t_process *p)
{
	t_exec	*exec;

	(void)p;
	exec = &data_singleton()->exec;
	dup2(exec->fd_save[0], STDIN);
	close(STDOUT);
	dup2(exec->fd_save[1], STDOUT);
	dup2(exec->fd_save[2], STDERR);
}
