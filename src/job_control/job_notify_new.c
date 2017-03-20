/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notify_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:27:01 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:26:31 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_notify_new(int id)
{
	t_list		*plist;
	t_process	*p;
	t_jobc		*jobc;
	t_job		*job;

	jobc = &data_singleton()->jobc;
	if (!(plist = ft_lst_find(jobc->first_job, &id, job_cmp_id)))
		return ;
	job = plist->content;
	plist = job->first_process;
	ft_printf("{mag}[%i]", job->id);
	while (plist)
	{
		p = plist->content;
		ft_printf(" %i", p->pid);
		plist = plist->next;
	}
	ft_printf("{eoc}\n");
}
