/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:47:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 11:16:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_format(t_job *j, int rank[2], int opts)
{
	t_list		*plist;
	int			firstp;

	job_format_head(j, rank);
	plist = j->first_process;
	firstp = 1;
	while (plist)
	{
		process_format(&plist, firstp, opts);
		firstp = 0;
	}
}
