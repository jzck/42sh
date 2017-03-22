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
	i = -1;
	while (++i < 10)
	{
		if (exec->fd_save[i] != -1)
			dup2(exec->fd_save[i], i);
	}
}
