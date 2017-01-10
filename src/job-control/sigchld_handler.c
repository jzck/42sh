/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigchld_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:37:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 17:59:28 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigchld_handler(int signo)
{
	t_data	*data;

	(void)signo;
	data = data_singleton();
	/* DG("got SIGCHLD"); */
	/* if (do_job_notification()) */
	/* 	ft_putstr(SHELL_PROMPT); */
	/* if (data_singleton()->mode != MODE_EXEC) */
	/* 	job_update_status(); */
}
