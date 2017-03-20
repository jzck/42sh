/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:54:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 18:50:44 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof		g_setprocessmap[] =
{
	{TK_WHILE, &pset_while},
	{TK_IF, &pset_if},
	{TK_UNTIL, &pset_until},
	{TK_FOR, &pset_for},
	{TK_CASE, &pset_case},
	{SUBSHELL, &pset_subshell},
	{CMD, &pset_cmd},
	{TK_LBRACE, &pset_brace},
	{0, NULL}
};

static int	process_set_spec(t_process *p, t_btree *ast)
{
	int			i;
	t_astnode	*item;

	i = -1;
	if (!ast)
		return (0);
	item = ast->item;
	while (g_setprocessmap[++i].id)
		if (item->type == g_setprocessmap[i].id)
		{
			if (!g_setprocessmap[i].f)
				return (1);
			return ((*g_setprocessmap[i].f)(p, ast));
		}
	return (1);
}

int			process_set(t_process *p, t_btree *ast)
{
	t_exec		*exec;
	int			op;
	int			fds[2];

	ft_bzero(p, sizeof(t_process));
	exec = &data_singleton()->exec;
	op = pop(&exec->op_stack);
	if ((EXEC_IS_AND_IF(exec->attrs)
	&& ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0") != 0)
	|| (EXEC_IS_OR_IF(exec->attrs)
	&& ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0") == 0))
		return (1);
	fds[PIPE_WRITE] = STDOUT;
	fds[PIPE_READ] = STDIN;
	(op == TK_PIPE) ? pipe(fds) : (0);
	exec->job.attrs |= (op == TK_AMP ? JOB_BG : 0);
	p->fdin = exec->fdin;
	p->to_close = fds[PIPE_READ];
	p->fdout = fds[PIPE_WRITE];
	exec->fdin = fds[PIPE_READ];
	if (!ast)
		return (0);
	p->redirs = ft_lstmap(((t_astnode *)ast->item)->data.cmd.redir,
																&redir_copy);
	return (process_set_spec(p, ast));
}
