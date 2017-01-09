/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_getrank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:38:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 12:47:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_getrank(int (*rank)[2])
{
	t_job		*job;
	t_jobc		*jobc;
	t_list		*jlist;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	(*rank)[0] = 0;
	(*rank)[1] = 0;
	if (jlist)
	{
		job = jlist->content;
		(*rank)[0] = job->id;
		jlist = jlist->next;
		if (jlist)
		{
			job = jlist->content;
			(*rank)[1] = job->id;
		}
	}
}
