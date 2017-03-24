/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_format_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:10:38 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 18:24:43 by jhalford         ###   ########.fr       */
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
	ft_printf("{mag}[%i]%c {eoc}", j->id, crank);
}
