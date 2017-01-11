/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:05:55 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 16:49:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	process_format(t_list **plist, int firstp, int opts)
{
	t_process	*p;
	int			state;

	p = (*plist)->content;
	if (!firstp)
		ft_printf("       ");
	if (opts & JOBS_OPTS_L)
		ft_printf("%i ", p->pid);
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
	if (opts & JOBS_OPTS_L)
	{
		ft_sstrprint(p->av, ' ');
		if ((*plist)->next)
			ft_putstr(" |");
		(*plist) = (*plist)->next;
	}
	else
	{
		while (*plist)
		{
			p = (*plist)->content;
			if (!(p->attributes & state) ||
					(state == PROCESS_COMPLETED && p->status != 0))
				break;
			if (p->attributes & PROCESS_CONTINUED)
			{
				p->attributes &= ~PROCESS_STATE_MASK;
				p->attributes &= ~PROCESS_RUNNING;
			}
			ft_sstrprint(p->av, ' ');
			if ((*plist)->next)
				ft_putstr(" | ");
			(*plist) = (*plist)->next;
		}
	}
	ft_putchar('\n');
}
