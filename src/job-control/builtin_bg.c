/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:54:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 11:11:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "job_control.h"

int		builtin_bg(const char *path, char *const av[], char *const envp[])
{
	t_jobc	*jobc;
	t_job	*job;
	t_list	*jlist;
	int		rank[2];
	int		id;

	(void)path;
	(void)envp;
	(void)av;
	jobc = &data_singleton()->jobc;
	job_getrank(&rank);
	id = av[1] ? ft_atoi(av[1]) : rank[0];
	if (id == 0 && !av[1])
		return (0);
	jlist = ft_lst_find(jobc->first_job, &id, job_cmp_id);
	if (jlist)
	{
		job = jlist->content;
		mark_job_as_running(job);
		job_format(job, rank, JOBS_OPTS_L);
		put_job_in_background(job, 1);
	}
	else
		ft_dprintf(2, "{red}bg: job not found: %i{eoc}\n", id);
	return (0);
}
