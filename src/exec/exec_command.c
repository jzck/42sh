/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:28:14 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/02 21:16:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char			**token_to_argv(t_cmd *cmd)
{
	char	**my_tab;
	int		index;
	char	**expand;
	char	**content;
	t_ld	*ld;

	ld = cmd->token;
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

int				exec_job(t_btree **ast)
{
	t_list		*cmd;
	t_process	p;
	t_list		*first_process;
	int			fds[2];

	cmd = ((t_astnode *)(*ast)->item)->data;
	exec = &data_singleton()->exec;
	if (pop(&exec.op_stack) == TK_AMP)
		exec->attrs |= JOB_BG;
	first_process = NULL;
	fds[PIPE_READ] = STDIN;
	while (cmd)
	{
		p.fdin = fds[PIPE_READ];
		p.fdout = cmd->next ? pipe(fds) && fds[PIPE_WRITE] : STDOUT;
		process_reset(&p);
		if (!(p.av = token_to_argv(cmd->content)))
			return (1);
		process_setexec(cmd->content, &p);
		if (!(launch_process(p)))
			ft_lstadd(&first_process, ft_lstnew(&p, sizeof(p)));
		cmd = cmd->next;
	}
	add_new_job(first_process, EXEC_IS_FG(exec->attrs));
	ft_lstadd(&jobc->first_job, ft_lstnew(&job, sizeof(*job)));
//	btree_delone(ast, &ast_free);
	return (0);
}
