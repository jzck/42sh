/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_is_stopped.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:06:45 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 14:41:16 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_is_stopped(t_job *job)
{
	t_list		*lst;
	t_process	*p;

	lst = job->first_process;
	while (lst)
	{
		p = lst->content;
		if (p->state != PROCESS_COMPLETED && p->state != PROCESS_SUSPENDED)
			return (0);
		lst = lst->next;
	}
	return (1);
}
