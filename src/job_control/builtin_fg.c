/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:30:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 11:00:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_fg(const char *path, char *const av[], char *const envp[])
{
	t_jobc	*jobc;
	t_list	*jlist;
	int		rank[2];
	int		id;

	(void)path;
	(void)envp;
	if (!SH_HAS_JOBC(data_singleton()->opts))
	{
		ft_dprintf(2, "{red}fg: %s{eoc}\n", SH_MSG_NOJOBC);
		return (-1);
	}
	jobc = &data_singleton()->jobc;
		job_getrank(&rank);
	if (av[1] ? (id = *av[1]) : 0)
	{
		if ((jlist = ft_lst_find(jobc->first_job, &id, job_cmp_id)))
			job_run(jlist->content, 1);
		else
			ft_dprintf(2, "{red}fg: job not found: [%i]{eoc}\n", id);
	}
	else
	{
		DG("rank:%i:%i", rank[0], rank[1]);
		if ((jlist = ft_lst_find(jobc->first_job, &rank[0], job_cmp_id)))
			job_run(jlist->content, 1);
		else if ((jlist = ft_lst_find(jobc->first_job, &rank[1], job_cmp_id)))
			job_run(jlist->content, 1);
		else
			ft_dprintf(2, "{red}fg: no current job{eoc}\n");
	}
	return (0);
}
