/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 13:16:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_command(t_btree **ast)
{
	t_astnode	*node;
	t_process	*p;
	t_job		*job;

	node = (*ast)->item;
	p = &data_singleton()->exec.process;
	job = &data_singleton()->exec.job;
	p->av = ft_sstrdup(node->data.sstr);
	process_setexec(p);
	if (!(launch_process(p)))
	{
		job_addprocess(p);
		if (IS_PIPEEND(p->attributes))
		{
			JOB_IS_FG(job->attributes) ?
				put_job_in_foreground(job, 0):
				put_job_in_background(job, 0);
			job->pgid = 0;
		}
	}
	p->av = NULL;
	p->pid = 0;
	p->attributes = PROCESS_PIPESTART | PROCESS_PIPEEND;
	btree_delone(ast, &ast_free);
	return (0);
}
