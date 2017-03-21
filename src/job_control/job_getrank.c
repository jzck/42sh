/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_getrank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:38:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:13:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_jobrank(t_list *jlist, int rank)
{
	t_job	*job;
	t_list	*head;
	int		ret;

	head = jlist;
	ret = 0;
	while (jlist && !ret)
	{
		job = jlist->content;
		if (job_is_stopped(job))
			rank ? rank-- : (ret = job->id);
		jlist = jlist->next;
	}
	jlist = head;
	while (jlist && !ret)
	{
		job = jlist->content;
		if (!job_is_stopped(job))
			rank ? rank-- : (ret = job->id);
		jlist = jlist->next;
	}
	return (ret);
}

void		job_getrank(int (*rank)[2])
{
	t_jobc	*jobc;
	t_list	*jlist;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	(*rank)[0] = get_jobrank(jlist, 0);
	(*rank)[1] = get_jobrank(jlist, 1);
}
