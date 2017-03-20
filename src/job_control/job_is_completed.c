/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_is_completed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:10:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:37:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_is_completed(t_job *job)
{
	t_list		*lst;
	t_process	*p;

	lst = job->first_process;
	while (lst)
	{
		p = lst->content;
		if (p->state != PROCESS_COMPLETED)
			return (0);
		lst = lst->next;
	}
	return (1);
}
