/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_is_completed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:10:20 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 15:24:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		job_is_completed(t_job *job)
{
	t_list		*lst;
	t_process	*process;

	lst = job->lst;
	while (lst)
	{
		process = lst->content;
		if (!(process->attributes & PROCESS_COMPLETED))
			return (0);
		lst = lst->next;
	}
	return (1);
}
