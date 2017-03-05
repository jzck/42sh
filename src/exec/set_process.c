/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:54:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/05 15:05:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		set_process(t_process *p, t_btree *ast)
{
	t_exec		*exec;
	t_cmd		*cmd;
	int			op;
	int			fds[2];

	cmd = &((t_astnode *)ast->item)->data.cmd;
	process_reset(p);
	exec = &data_singleton()->exec;
	op = pop(&exec->op_stack);
	if (!(p->av = token_to_argv(cmd->token, 1)))
		return (1);
	fds[PIPE_WRITE] = STDOUT;
	fds[PIPE_READ] = STDIN;
	if (op == TK_AMP)
		exec->attrs |= JOB_BG;
	else if (op == TK_PIPE)
		pipe(fds);
	p->fdin = exec->fdin;
	p->to_close = fds[PIPE_READ];
	p->fdout = fds[PIPE_WRITE];
	exec->fdin = fds[PIPE_READ];
	p->redirs = cmd->redir;
	process_setexec(p);
	return (0);
}
