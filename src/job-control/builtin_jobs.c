/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_jobs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:43:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 14:38:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"


int		builtin_jobs(const char *path, char *const av[], char *const envp[])
{
	t_jobc		*jobc;
	t_list		*jlist;
	t_list		*tmplist;
	int			rank[2];
	int			opts;

	(void)path;
	(void)envp;
	(void)av;
	if (!SHELL_HAS_JOBC(data_singleton()->opts))
	{
		ft_dprintf(2, "{red}jobs: %s{eoc}\n", SHELL_MSG_NOJOBC);
		return (-1);
	}
	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	job_getrank(&rank);
	opts = 0;
	if (ft_strcmp(av[1], "-l") == 0)
		opts |= JOBS_OPTS_L;
	tmplist = ft_lst_filter(jlist, NULL, NULL);
	ft_lstsort(&tmplist, job_cmp_id);
	jlist = tmplist;
	while (jlist)
	{
		job_format(jlist->content, rank, opts);
		jlist = jlist->next;
	}
	ft_lstdel(&tmplist, ft_lst_cfree);
	return (0);
}
