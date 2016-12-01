/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:43:22 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/01 14:27:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
pid_t	g_pid;

void	sig_handler(int signo)
{
	(void)signo;
	/* if (signo == SIGINT) */
	/* { */
	/* 	ft_printf("got SIGINT, g_pid = %i\n", g_pid); */
	/* 	if (g_pid) */
	/* 		kill(g_pid, SIGINT); */
	/* 	if (kill(g_pid, 0) == 0) */
	/* 		ft_putendl(""); */
	/* } */
}
