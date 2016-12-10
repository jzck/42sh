/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:14:47 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 15:31:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;

void	sigint_handler(int signo)
{
	(void)signo;
	if (signo == SIGINT)
	{
		DG("got SIGINT");
		if (g_pid)
			kill(g_pid, SIGINT);
		if (kill(g_pid, 0) == 0)
			ft_putendl("");
	}
}
