/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notify_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:27:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:15:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_notify_new(t_job *job)
{
	t_list		*plist;
	t_process	*p;

	ft_printf("{mag}[%i]", job->id);
	plist = job->first_process;
	while (plist)
	{
		p = plist->content;
		ft_printf(" %i", p->pid);
		plist = plist->next;
	}
	ft_printf("{eoc}\n");
}
