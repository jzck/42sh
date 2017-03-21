/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:06:44 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 14:48:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_format(t_job *j, int opts)
{
	t_list		*plist;
	int			firstp;

	job_format_head(j);
	plist = j->first_process;
	firstp = 1;
	while (plist)
	{
		process_format(&plist, firstp, opts);
		firstp = 0;
	}
}
