/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:20:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 16:49:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_launchmap[] =
{
	{PROCESS_FUNCTION, NULL},
	{PROCESS_BUILTIN, launch_builtin},
	{PROCESS_FILE, launch_file},
	{PROCESS_SUBSHELL, NULL},
	{PROCESS_WHILE, NULL},
	{PROCESS_IF, NULL},
	{PROCESS_FOR, NULL},
	{PROCESS_CASE, NULL},
	{0, NULL}
};

int		launch_process(t_process *p)
{
	int			i;
	int			pid;

	i = 0;
	while (g_launchmap[i].id)
	{
		if (p->type == g_launchmap[i].id)
		{
			if (!g_launchmap[i].f)
				return (-1);
			p->attrs &= ~PROCESS_STATE_MASK;
			p->attrs |= PROCESS_RUNNING;
			if ((pid = (*g_launchmap[i].f)(p)))
			{
				p->pid = pid;
				process_setgroup(p, pid);
				return (0);
			}
		}
		i++;
	}
	return (-1);
}
