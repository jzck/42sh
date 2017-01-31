/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_cmp_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:38:13 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 15:06:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		job_cmp_id(t_job *job, int *id)
{
	return (job->id - *id);
}
