/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:05:55 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 15:10:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

static void	process_format_state(t_process *p)
{
	int			state;

	state = p->attributes & PROCESS_STATE_MASK;
	if (state == PROCESS_RUNNING)
		ft_putstr("running  ");
	else if (state == PROCESS_SUSPENDED)
		ft_putstr("suspended");
	else if (state == PROCESS_CONTINUED)
	{
		ft_putstr("continued");
		p->attributes &= ~PROCESS_STATE_MASK;
		p->attributes |= PROCESS_RUNNING;
	}
	else if (state == PROCESS_COMPLETED)
	{
		if (p->status == 0)
			ft_putstr("done     ");
		else
			ft_printf("exit %i  ", p->status);
	}
	ft_putchar('\t');
}

static void	process_format_com_long(t_list **plist)
{
	t_process	*p;

	p = (*plist)->content;
	if (p->attributes & PROCESS_SUBSHELL)
	{
		ft_putstr("( ");
		ft_putstr(p->av[2]);
		ft_putstr(" )");
	}
	else
		ft_sstrprint(p->av, ' ');
	if ((*plist)->next)
		ft_putstr(" |");
	(*plist) = (*plist)->next;
}

static void	process_format_com_short(t_list **plist, t_flag state)
{
	t_process	*p;

	while (*plist)
	{
		p = (*plist)->content;
		if (!(p->attributes & state) ||
				(state == PROCESS_COMPLETED && p->status != 0))
			break ;
		if (p->attributes & PROCESS_CONTINUED)
		{
			p->attributes &= ~PROCESS_STATE_MASK;
			p->attributes &= ~PROCESS_RUNNING;
		}
		if (p->attributes & PROCESS_SUBSHELL)
		{
			ft_putstr("( ");
			ft_putstr(p->av[2]);
			ft_putstr(" )");
		}
		else
			ft_sstrprint(p->av, ' ');
		if ((*plist)->next)
			ft_putstr(" | ");
		(*plist) = (*plist)->next;
	}
}

void		process_format(t_list **plist, int firstp, int opts)
{
	t_process	*p;
	t_flag		state;

	p = (*plist)->content;
	state = p->attributes & PROCESS_STATE_MASK;
	if (!firstp)
		ft_printf("       ");
	if (opts & JOBS_OPTS_L)
		ft_printf("%i ", p->pid);
	process_format_state(p);
	if (opts & JOBS_OPTS_L)
		process_format_com_long(plist);
	else
		process_format_com_short(plist, state);
	ft_putchar('\n');
}
