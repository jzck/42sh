/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notify_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:04:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 12:39:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_notify_change(int id, int status)
{
	t_job		*job;
	t_jobc		*jobc;
	t_list		*plist;
	t_process	*p;
	char		rank;

	rank = ' ';
	jobc = &data_singleton()->jobc;
	job = jobc->first_job->content;
	if (id == job->id)
		rank = '+';
	else if (jobc->first_job->next)
	{
		job = jobc->first_job->next->content;
		if (id == job->id)
			rank = '-';
	}
	ft_printf("{mag}[%i]  %c ", id, rank);
	job = ft_lst_find(jobc->first_job, &id, job_cmp_id)->content;
	if (status == -1)
		ft_printf("{red}stopped{mag}");
	else
	{
		plist = job->first_process;
		p = ft_lstlast(job->first_process)->content;
		if (p->status == 0)
			ft_printf("{gre}done{mag}");
		else
			ft_printf("{red}exit %i{mag}", p->status);
	}
	ft_printf("\t ");
	plist = job->first_process;
	while (plist)
	{
		p = plist->content;
		ft_sstrprint(p->av, ' ');
		if (plist->next)
			ft_printf(" |");
		plist = plist->next;
	}
	ft_printf("{eoc}\n");
}
