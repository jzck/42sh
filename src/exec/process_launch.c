/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_launch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 22:21:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 01:52:43 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* t_itof	g_launchmap[] = */
/* { */
/* 	{PROCESS_FUNCTION, launch_function}, */
/* 	{PROCESS_BUILTIN, launch_builtin}, */
/* 	{PROCESS_FILE, launch_file}, */
/* 	{PROCESS_SUBSHELL, launch_subshell}, */
/* 	{PROCESS_BRACE, launch_brace}, */
/* 	{PROCESS_WHILE, launch_while}, */
/* 	{PROCESS_UNTIL, launch_until}, */
/* 	{PROCESS_IF, launch_if}, */
/* 	{PROCESS_FOR, launch_for}, */
/* 	{PROCESS_CASE, launch_case}, */
/* 	{PROCESS_EMPTY, launch_empty}, */
/* }; */

int		process_launch(t_process *p)
{
	int			pid;

	DG("p->type=%i", p->type);
	/* if (p->type >= PROCESS_MAX) */
	/* 	return (-1); */
	/* if (!g_launch_map[p->type].f) */
	/* 	return (-1); */
	p->attrs &= ~PROCESS_STATE_MASK;
	p->attrs |= PROCESS_RUNNING;
	if (!(pid = (*p->map.launch)(p)))
	{
		DG("launcher did not fork!");
		process_resetfds(p);
		return (1);
	}
	DG("launcher forked!");
	p->pid = pid;
	process_setgroup(p, pid);
	if (p->fdin != STDIN)
		close(p->fdin);
	if (p->fdout != STDOUT)
		close(p->fdout);
	return (0);
}
