/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:43:22 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 13:31:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_pid;

void	sig_handler(int signo)
{
	(void)signo;
	if (signo == SIGINT)
	{
		if (g_pid)
			kill(g_pid, SIGINT);
		if (kill(g_pid, 0) == 0)
			ft_putendl("");
	}
}
