/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 13:22:16 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	job_free(void *content, size_t content_size)
{
	t_job	*job;

	(void)content_size;
	job = content;
	ft_lstdel(&job->first_process, &process_free);
	free(job);
}
