/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_is_stopped.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:06:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 12:42:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_is_stopped(int id)
{
	t_list		*lst;
	t_job		*job;
	t_jobc		*jobc;
	t_process	*p;

	jobc = &data_singleton()->jobc;
	job = ft_lst_find(jobc->first_job, &id, job_cmp_id)->content;
	lst = job->first_process;
	while (lst)
	{
		p = lst->content;
		if (!(p->attributes & (PROCESS_COMPLETED | PROCESS_STOPPED)))
			return (0);
		lst = lst->next;
	}
	return (1);
}
