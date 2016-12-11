/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:51:54 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 17:58:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_new(t_data *data, char **av, pid_t pid)
{
	t_job	job;

	DG("got new job");
	job.command = ft_sstrcat(av, ' ');
	DG("job command '%s'", job.command);
	job.pid = pid;
	job.id = 42;
	ft_lstadd(&data->jobc.list, ft_lstnew(&job, sizeof(job)));
	job_announce(data->jobc.list->content);
}
