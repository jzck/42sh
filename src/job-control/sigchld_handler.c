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

void	sigchld_handler(int signo)
{
	int		status;
	pid_t	pid;
	t_job	*job;
	t_list	*start;
	t_list	*list;

	(void)signo;
	DG("got SIGCHLD");
	start = data_singleton()->jobc.list;
	pid = waitpid(-1, &status, WNOHANG);
	DG("SIGCHLD pid=%i", pid);
	/* start = NULL; */
	list = start ? ft_lst_find(start, &pid, ft_cmppid) : NULL;
	if (list)
	{
		job = list->content;
		if (status == 0)
			ft_printf("[%i]  + done\t%s\n", job->id, job->command);
		else
			ft_printf("[%i]  + exit %i\t%s\n", job->id, status, job->command);
		ft_prompt();
	}
	else
		DG("SIGCHLD but no find");

}
