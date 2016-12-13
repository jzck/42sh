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
	t_process	*process;
	t_job		*job;

	node = (*ast)->item;
	process = &data_singleton()->exec.process;
	job = &data_singleton()->exec.job;
	process->argv = ft_sstrdup(node->data.sstr);
	DG("gonna launch_process");
	process_setexec(process);
	launch_process(process);
	job_addprocess(process);
	btree_delone(ast, &ast_free);
	return (0);
}
