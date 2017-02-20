/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 16:54:18 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/20 00:09:28 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		builtin_bg(const char *path, char *const av[], char *const envp[])
{
	t_jobc	*jobc;
	t_list	*jlist;
	int		rank[2];
	int		id;

	(void)path;
	(void)envp;
	if (!SH_HAS_JOBC(data_singleton()->opts))
	{
		ft_dprintf(2, "{red}bg: %s{eoc}\n", SH_MSG_NOJOBC);
		return (-1);
	}
	jobc = &data_singleton()->jobc;
	job_getrank(&rank);
	id = av[1] ? ft_atoi(av[1]) : rank[0];
	if ((jlist = ft_lst_find(jobc->first_job, &id, job_cmp_id)))
	{
		job_run(jlist->content, 0);
		return (0);
	}
	else if (av[1])
		ft_dprintf(2, "{red}bg: job not found: %i{eoc}\n", id);
	else
		ft_dprintf(2, "{red}bg: no current job{eoc}\n");
	return (1);
}
