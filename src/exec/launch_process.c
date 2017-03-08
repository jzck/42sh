/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:20:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 20:46:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_launchmap[] =
{
	{PROCESS_FUNCTION, launch_function},
	{PROCESS_BUILTIN, launch_builtin},
	{PROCESS_FILE, launch_file},
	{PROCESS_SUBSHELL, launch_subshell},
	{PROCESS_WHILE, launch_while},
	{PROCESS_UNTIL, launch_until},
	{PROCESS_IF, launch_if},
	{PROCESS_FOR, launch_for},
	{PROCESS_CASE, launch_case},
};

int		launch_process(t_process *p)
{
	int			pid;

	DG("launchprocess");
	if (p->type >= PROCESS_MAX)
		return (-1);
	if (!g_launchmap[p->type].f)
		return (-1);
	p->attrs &= ~PROCESS_STATE_MASK;
	p->attrs |= PROCESS_RUNNING;
	if (!(pid = (*g_launchmap[p->type].f)(p)))
		return (-1);
	p->pid = pid;
	process_setgroup(p, pid);
	return (0);
}
