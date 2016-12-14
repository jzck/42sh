/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 17:41:09 by jhalford         ###   ########.fr       */
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
	DG("gonna launch_process");
	DG("job attr=%i", job->attributes);
	process_setexec(p);
	launch_process(p);
	if (p->fdout == STDOUT)
	{
		if (JOB_IS_FG(job->attributes))
			put_job_in_foreground(job, 0);
		else
			put_job_in_background(job, 0);
	}
	job_addprocess(p);
	btree_delone(ast, &ast_free);
	return (0);
}
