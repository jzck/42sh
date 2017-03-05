/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigtstp_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:14:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 15:30:58 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigtstp_handler(int signo)
{
//	t_jobc	*jobc;

	(void)signo;
//	jobc = &data_singleton()->jobc;
	DG("got SIGTSTP pid=%i, pgrp=%i, shell_pgid=%i", getpid(), getpgrp(), data_singleton()->jobc.shell_pgid);
	ft_putchar('\x1A');
}
