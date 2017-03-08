/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:51:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 00:36:12 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_remove(int id)
{
	t_jobc		*jobc;
	t_job		*j;
	t_process	*p;

	jobc = &data_singleton()->jobc;
	j = ft_lst_find(jobc->first_job, &id, job_cmp_id)->content;
	if (job_is_completed(id))
	{
		DG();
		p = ft_lstlast(j->first_process)->content;
		set_exitstatus(p->status, 0);
		if (id < data_singleton()->jobc.current_id)
			data_singleton()->jobc.current_id = id;
		ft_lst_delif(&jobc->first_job, &id, job_cmp_id, job_free);
	}
}
