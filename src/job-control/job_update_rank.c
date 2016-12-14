/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_shiftstatus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:05:10 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 17:23:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_update_rank()
{
	t_jobc	*jobc;
	t_job	*job;
	t_list	*list;

	jobc = &data_singleton()->jobc;
	list = jobc->first_job;
	if (list)
	{
		job = list->content;
		jobc->rank[0] = job->id;
		jobc->rank[1] = list->next ? ((t_job*)list->next->content)->id : 0;
	}
	else
	{
		jobc->rank[0] = 0;
		jobc->rank[1] = 0;
	}
	DG("updated rank: %i,%i", jobc->rank[0], jobc->rank[1]);
}
