/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:30:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 14:42:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		builtin_fg(const char *path, char *const av[], char *const envp[])
{
	t_jobc	*jobc;
	t_job	*job;
	t_list	*jlist;
	int		rank[2];
	int		id;

	(void)path;
	(void)envp;
	(void)av;
	if (!SHELL_HAS_JOBC(data_singleton()->opts))
	{
		ft_dprintf(2, "{red}fg: %s{eoc}\n", SHELL_MSG_NOJOBC);
		return (-1);
	}
	jobc = &data_singleton()->jobc;
	job_getrank(&rank);
	id = av[1] ? ft_atoi(av[1]) : rank[0];
	jlist = ft_lst_find(jobc->first_job, &id, job_cmp_id);
	if (jlist)
	{
		job = jlist->content;
		mark_job_as_running(job);
		put_job_in_foreground(job, 1);
		return (0);
	}
	else if (av[1])
		ft_dprintf(2, "{red}fg: job not found: [%i]{eoc}\n", id);
	else
		ft_dprintf(2, "{red}fg: no current job{eoc}\n");
	return (1);
}
