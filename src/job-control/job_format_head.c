/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_format_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:10:38 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 14:53:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	job_format_head(t_job *j)
{
	char	crank;
	int		rank[2];

	job_getrank(&rank);
	if (j->id == rank[0])
		crank = '+';
	else if (j->id == rank[1])
		crank = '-';
	else
		crank = ' ';
	ft_printf("{mag}[%i]  %c ", j->id, crank);
	ft_printf("{eoc}");
}
