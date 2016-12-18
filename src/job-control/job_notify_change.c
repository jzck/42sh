/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notify_change.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:04:03 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:45:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_notify_change(t_job *job, int status)
{
	char	rank;

	rank = ' ';
	if (job->id == data_singleton()->jobc.rank[0])
		rank = '+';
	else if (job->id == data_singleton()->jobc.rank[1])
		rank = '-';
	ft_printf("{mag}[%i]  %c ", job->id, rank);
	if (status == 0)
		ft_printf("{gre}done{mag}");
	else if (status == 8)
		ft_printf("{red}stopped{mag}");
	else if (status == 9)
		ft_printf("{red}killed{mag}");
	else
		ft_printf("exit %i", status);
	ft_printf("\t 'process command goes here'{eoc}\n");
}
