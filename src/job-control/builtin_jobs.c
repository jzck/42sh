/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:43:01 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:54:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		builtin_jobs(const char *path, char *const av[], char *const envp[])
{
	t_jobc	*jobc;
	t_list	*jlist;
	t_job	*job;
	char	rank;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	(void)path;
	(void)envp;
	(void)av;
	while (jlist)
	{
		job = jlist->content;
		rank = ' ';
		if (job->id == data_singleton()->jobc.rank[0])
			rank = '+';
		else if (job->id == data_singleton()->jobc.rank[1])
			rank = '-';
		ft_printf("{mag}[%i]  %c ", job->id, rank);
		ft_printf("attributes=%x{eoc}\n", job->attributes);
		jlist = jlist->next;
	}
	return (0);
}
