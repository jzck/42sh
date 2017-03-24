/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:07:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 20:09:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_resetsig(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, SIG_DFL);
}

void	shell_resetfds(void)
{
	t_exec	*exec;
	int		i;
	int		fd;

	exec = &data_singleton()->exec;
	i = -1;
	while (++i < 10)
	{
		fd = top(exec->fd_save[i]);
		if (fd != -1)
			dup2(fd, i);
	}
}
