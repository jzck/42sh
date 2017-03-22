/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:30:07 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 16:30:05 by gwojda           ###   ########.fr       */
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
		SH_ERR("fg: %s", SH_MSG_NOJOBC);
		return (-1);
	}
	jobc = &data_singleton()->jobc;
	job_getrank(&rank);
	if (av[1] ? (id = *av[1]) : 0)
	{
		if ((jlist = ft_lst_find(jobc->first_job, &id, job_cmp_id)))
			job_run(jlist->content, 1);
		else
			SH_ERR("{red}fg: job not found: [%i]", id);
	}
	else
	{
		if ((jlist = ft_lst_find(jobc->first_job, &rank[0], job_cmp_id)))
			job_run(jlist->content, 1);
		else if ((jlist = ft_lst_find(jobc->first_job, &rank[1], job_cmp_id)))
			job_run(jlist->content, 1);
		else
			SH_ERR("fg: no current job");
	}
	return (0);
}
