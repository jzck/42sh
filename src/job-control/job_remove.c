/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_remove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:51:08 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 13:44:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_remove(int id)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	if (job_is_completed(id))
	{
		if (id < data_singleton()->jobc.current_id)
			data_singleton()->jobc.current_id = id;
		ft_lst_delif(&jobc->first_job, &id, job_cmp_id, job_free);
	}
}
