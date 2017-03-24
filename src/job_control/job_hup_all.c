/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_hup_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:37:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 17:22:42 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_hup_all(void)
{
	t_jobc		*jobc;
	t_list		*jlist;
	t_job		*job;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	if (!SH_HAS_JOBC(data_singleton()->opts))
		return ;
	while (jlist)
	{
		job = jlist->content;
		builtin_jobs(NULL, NULL, NULL);
		if (job->pgid != 1)
			kill(-job->pgid, SIGHUP);
		jlist = jlist->next;
	}
}
