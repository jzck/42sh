/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_leaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:47:30 by wescande          #+#    #+#             */
/*   Updated: 2017/03/11 16:00:12 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				exec_leaf(t_btree **ast)
{
	t_process	p;
	t_job		*job;

	job = &data_singleton()->exec.job;
	if (set_process(&p, *ast))
		return (1);
	if (!(launch_process(&p)))
	{
		DG("forked pid=[%i], name=[%s]", p.pid, p.data.cmd.av[0]);
		job_addprocess(&p);
		DG("[IS_BG->%i]", JOB_IS_BG(job->attrs));
		if (IS_PIPEEND(p))
		{
			if (JOB_IS_FG(job->attrs))
				put_job_in_foreground(job, 0);
			job->pgid = 0;
		}
	}
	return (0);
}
