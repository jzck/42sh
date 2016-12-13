/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notify_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:27:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 14:58:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_notify_new(t_job *job)
{
	t_list	*process;

	process = job->first_process;
	ft_printf("{mag}[%i]", job->id);
	while (process)
	{
		ft_printf(" %i", ((t_process*)process->content)->pid);
		process=process->next;
	}
	ft_printf("{eoc}\n");
}
