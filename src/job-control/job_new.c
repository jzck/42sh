/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 16:51:54 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 11:53:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_new(char **av, pid_t pid)
{
	t_job	job;
	t_data	*data;

	data = data_singleton();
	DG("got new job");
	if (data->mode == MODE_INPUT)
		DG("am in MODE_INPUT");
	else if (data->mode == MODE_EXEC)
		DG("am in MODE_EXEC");
	job.command = ft_sstrcat(av, ' ');
	DG("job command '%s'", job.command);
	job.pid = pid;
	job_update_id();
	DG("id = %i", data->jobc.current_id);
	job.id = data->jobc.current_id;
	data->jobc.rank[1] = data->jobc.rank[0];
	data->jobc.rank[0] = job.id;
	ft_lstadd(&data->jobc.list, ft_lstnew(&job, sizeof(job)));
	job_announce(data->jobc.list->content);
}
