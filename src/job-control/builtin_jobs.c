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
	rank = '+';
	while (jlist)
	{
		DG("jlist->content");
		job = jlist->content;
		ft_printf("{mag}jobs: [%i]  %c ", job->id, rank);
		ft_printf("attributes=%x{eoc}\n", job->attributes);
		jlist = jlist->next;
		rank = (rank == '+') ? '-' : ' ';
	}
	return (0);
}
