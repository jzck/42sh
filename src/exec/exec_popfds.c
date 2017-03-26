/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_popfds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:31:05 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 21:31:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_popfds(void)
{
	int		i;
	t_exec	*exec;

	exec = &data_singleton()->exec;
	i = -1;
	while (++i < 10)
		pop(&exec->fd_save[i]);
	return (0);
}
