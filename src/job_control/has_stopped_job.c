/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_stopped_job.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:40:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 14:41:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		has_stopped_job(void)
{
	t_jobc		*jobc;
	t_list		*jlist;
	t_job		*j;

	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	while (jlist)
	{
		j = jlist->content;
		if (job_is_stopped(j))
			return (1);
		jlist = jlist->next;
	}
	return (0);
}
