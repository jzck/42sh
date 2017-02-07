/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_resetfds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:39:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 17:50:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_resetfds(void)
{
	t_exec	*exec;

	exec = &data_singleton()->exec;
	dup2(exec->fd0save, 0);
	dup2(exec->fd1save, 1);
	dup2(exec->fd2save, 2);
}
