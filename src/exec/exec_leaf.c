/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_leaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:47:30 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 15:50:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int				exec_leaf(t_btree **ast)
{
	t_process	p;
	t_job		*job;

	job = &data_singleton()->exec.job;
	if (set_process(&p, *ast))
		return (1);
	if (!(launch_process(&p)))
	{
		job_addprocess(&p);
		if (IS_PIPEEND(p))
		{
			if (JOB_IS_FG(job->attrs))
				put_job_in_foreground(job, 0);
			else
				put_job_in_background(job, 0);
		}
		job->pgid = 0;
	}
	if (p.fdout != STDOUT)
		close(p.fdout);
	return (0);
}
