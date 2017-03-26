/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pushfds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:31:46 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 21:34:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_pushfds(void)
{
	int		i;
	t_exec	*exec;

	exec = &data_singleton()->exec;
	i = -1;
	while (++i < 10)
		push(&(exec->fd_save[i]), fcntl(i, F_DUPFD_CLOEXEC, 10));
	return (0);
}
