/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_hup_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:37:40 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 11:37:53 by jhalford         ###   ########.fr       */
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
	while (jlist)
	{
		job = jlist->content;
		kill(-job->pgid, SIGHUP);
		jlist = jlist->next;
	}
}
