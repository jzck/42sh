/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_addprocess.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:54:51 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 01:30:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_addprocess(t_process *p)
{
	t_jobc	*jobc;
	t_job	*job;

	jobc = &data_singleton()->jobc;
	job = &data_singleton()->exec.job;
	if (IS_PIPESTART(*p))
	{
		job_update_id();
		job->id = jobc->current_id;
		job->pgid = SH_IS_INTERACTIVE(data_singleton()->opts) ?
			/* p->pid : data_singleton()->jobc.shell_pgid; */
		p->pid : getpgid(0);
		ft_lstadd(&jobc->first_job, ft_lstnew(job, sizeof(*job)));
	}
	job = jobc->first_job->content;
	ft_lsteadd(&job->first_process, ft_lstnew(p, sizeof(*p)));
	return (0);
}
