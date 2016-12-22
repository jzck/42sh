/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 18:31:12 by jhalford         ###   ########.fr       */
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
	p->argv = ft_sstrdup(node->data.sstr);
	if (process_setexec(p))
	{
		ft_dprintf(2, "{red}%s: command not found: %s{eoc}\n", SHELL_NAME, p->argv[0]);
		p->attributes = 0;
		p->path = NULL;
		p->argv = NULL;
		btree_delone(ast, &ast_free);
		return (0);
	}
	DG("gonna launch_process now");
	launch_process(p);
	job_addprocess(p);
	if (IS_PIPEEND(p->fdout == STDOUT))
	{
		if (JOB_IS_FG(job->attributes))
			put_job_in_foreground(job, 0);
		else
			put_job_in_background(job, 0);
	}
	btree_delone(ast, &ast_free);
	p->attributes = 0;
	p->path = NULL;
	p->argv = NULL;
	return (0);
}
