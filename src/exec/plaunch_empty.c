/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:26:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 20:29:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		plaunch_empty(t_process *p)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (process_redirect(p))
			exit (1);
		process_setgroup(p, 0);
		process_setsig();
		exec_reset();
		DG("empty exit");
		exit(0);
	}
	else if (pid > 0)
		return (pid);
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (0);
}

