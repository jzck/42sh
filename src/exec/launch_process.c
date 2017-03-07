/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:20:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 15:04:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_itof	g_launchmap[] =
{
	{PROCESS_FUNCTION, NULL},
	{PROCESS_BUILTIN, NULL},
	{PROCESS_FILE, launch_file},
	{PROCESS_SUBSHELL, NULL},
	{PROCESS_WHILE, NULL},
	{PROCESS_IF, NULL},
	{PROCESS_FOR, NULL},
	{PROCESS_CASE, NULL},
};

int		launch_process(t_process *p)
{
	int			i;

	i = 0;
	/* DG("gonna launch [%s]", p->av[0]); */
	/* DG("fdin=[%i]", p->fdin); */
	/* DG("fdout=[%i]", p->fdout); */
	while (g_launchmap[i].type)
	{
		if (p->type == g_launchmap[i].type)
			if (!g_launchmap[i].f)
				return (-1);
			return ((*g_launchmap[i].f)(p));
		i++;
	}
	return (-1);
}
