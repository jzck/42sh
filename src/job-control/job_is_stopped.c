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

int		job_is_stopped(t_job *job)
{
	t_list		*lst;
	t_process	*p;

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
