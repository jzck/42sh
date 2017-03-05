/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 15:14:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char			**token_to_argv(t_ld *ld, int do_match)
{
	char	**my_tab;
	int		index;
	char	**expand;
	char	**content;

	my_tab = NULL;
	while (ld)
	{
		content = ld->content;
		if ((expand = glob(content[0], (unsigned char *)content[1], (unsigned char *)content[2], do_match)))
		{
			index = -1;
			while (expand[++index])
				my_tab = ft_sstradd(my_tab, expand[index]);
			ft_tabdel(&expand);
		}
		ld = ld->next;
	}
	return (my_tab);
}

int				exec_cmd(t_btree **ast)
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
