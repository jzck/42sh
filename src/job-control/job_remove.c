/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:51:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/02 18:15:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_remove(t_job *job)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	if (job->id < data_singleton()->jobc.current_id)
	{
		data_singleton()->jobc.current_id = job->id;
		DG("ID_UPDATE(downgrade):%i", job->id);
	}
	else
		DG("ID_UPDATE(no downgrade): %i/%i", job->id, data_singleton()->jobc.current_id);
	ft_lst_delif(&jobc->first_job, job, ft_addrcmp, job_free);
}
