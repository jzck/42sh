/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/21 22:41:01 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char		**token_to_argv(t_astnode *node)
{
	char	**my_tab;
	int		index;
	char	**expand;
	char	**content;
	t_ld	*ld;

	if (node->type == TK_COMMAND)
	{
		ld = node->data.token;
		my_tab = NULL;
		while (ld)
		{
			content = ld->content;
			if ((expand = glob(content[0], (unsigned char *)content[1], (unsigned char *)content[2])))
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
	else if (node->type == TK_SUBSHELL)
		return (ft_sstrdup(node->data.sstr));
	return (NULL);
}

int				exec_command(t_btree **ast)
{
	t_astnode	*node;
	t_process	*p;
	t_job		*job;
	int			fds[2];

	node = (*ast)->item;
	p = &data_singleton()->exec.process;
	job = &data_singleton()->exec.job;
	if (!(p->av = token_to_argv(node)))
	{
		DG("globbing error");
		return (1);
	}
	process_setexec(node->type, p);
	if (p->pipe_count)
	{
		pipe(fds);
		p->fdout = fds[PIPE_WRITE];
		p->to_close = fds[PIPE_READ];
		p->pipe_count--;
	}
	if (!(launch_process(p)))
	{
		job_addprocess(p);
		if (IS_PIPEEND(p))
		{
			JOB_IS_FG(job->attributes) ?
				put_job_in_foreground(job, 0):
				put_job_in_background(job, 0);
			job->pgid = 0;
		}
	}
	if (p->fdout == fds[PIPE_WRITE])
		p->fdin = fds[PIPE_READ];
	process_reset(p);
//	btree_delone(ast, &ast_free);
	return (0);
}
