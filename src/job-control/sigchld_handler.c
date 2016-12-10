/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigchld_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 17:37:56 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 18:25:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*g_data;

void	sigchld_handler(int signo)
{
	t_job	*job;
	t_list	*list;

	(void)signo;
	DG("got SIGCHLD");
	list = g_data->jobc.list;
	if (list)
		job = list->content;
	else
		job = NULL;
	if (job)
		DG("job pid=%i", job->pid);
}
