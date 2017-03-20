/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_leaf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:47:30 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 12:47:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process_map	g_process_map[] =
{
	{PROCESS_FUNCTION, plaunch_function, pprint_function, pfree_subshell},
	{PROCESS_BUILTIN, plaunch_builtin, pprint_cmd, pfree_cmd},
	{PROCESS_FILE, plaunch_file, pprint_cmd, pfree_cmd},
	{PROCESS_SUBSHELL, plaunch_subshell, pprint_subshell, pfree_subshell},
	{PROCESS_BRACE, plaunch_brace, pprint_brace, pfree_subshell},
	{PROCESS_WHILE, plaunch_while, pprint_while, pfree_cond},
	{PROCESS_UNTIL, plaunch_until, pprint_until, pfree_cond},
	{PROCESS_IF, plaunch_if, pprint_if, pfree_cond},
	{PROCESS_FOR, plaunch_for, pprint_for, pfree_list},
	{PROCESS_CASE, plaunch_case, pprint_case, pfree_list},
	{PROCESS_EMPTY, plaunch_empty, NULL, NULL},
};

int				exec_leaf(t_btree **ast)
{
	t_process	p;
	t_job		*job;

	job = &data_singleton()->exec.job;
	if (process_set(&p, *ast))
		return (1);
	if (p.type >= PROCESS_MAX)
		return (1);
	p.map = g_process_map[p.type];
	if (!(process_launch(&p)))
	{
		job_addprocess(&p);
		if (IS_PIPEEND(p))
		{
			if (JOB_IS_FG(job->attrs))
				put_job_in_foreground(job, 0);
			else
				job_notify_new(job->id);
			job->pgid = 0;
		}
	}
	return (0);
}
