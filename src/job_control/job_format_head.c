/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_format_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:10:38 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 14:55:16 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_format_head(t_job *j)
{
	char	crank;
	int		rank[2];

	job_getrank(&rank);
	crank = j->id == rank[0] ? '+' : ' ';
	crank = j->id == rank[1] ? '-' : crank;
	DG("raks [%i:%i]", rank[0], rank[1]);
	ft_printf("{mag}[%i]%c {eoc}", j->id, crank);
}
