/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 18:44:43 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char			**token_to_argv(t_ld *ld)
{
	char	**my_tab;
	int		index;
	char	**expand;
	char	**content;

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

int				exec_cmd(t_btree **ast)
{
	t_cmd		*cmd;
	t_job		*job;
	t_exec		*exec;
	t_process	p;
	int			fds[2];
	int			op;

	cmd = &((t_astnode *)(*ast)->item)->data.cmd;
	exec = &data_singleton()->exec;
	job = &data_singleton()->exec.job;
	process_reset(&p);
	op = pop(&exec->op_stack);
	DG("op=%i", op);
	fds[PIPE_WRITE] = STDOUT;
	fds[PIPE_READ] = STDIN;
	if (op == TK_AMP)
		exec->attrs |= JOB_BG;
	else if (op == TK_PIPE)
		pipe(fds);
	p.fdin = exec->fdin;
	p.fdout = fds[PIPE_WRITE];
	exec->fdin = fds[PIPE_READ];
	if (IS_PIPESTART(p))
	{
		job->first_process = NULL;
		job->attrs = EXEC_IS_FG(exec->attrs) ? 0 : JOB_BG;
	}
	if (!(p.av = token_to_argv(cmd->token)))
		return (1);
	process_setexec(&p);
	if (!(launch_process(&p)))
		ft_lstadd(&job->first_process, ft_lstnew(&p, sizeof(p)));
	if (IS_PIPEEND(p))
		add_new_job(job);
	return (0);
}
