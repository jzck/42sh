/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:41:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/02 14:34:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

void	process_free(void *content, size_t content_size)
{
	t_process	*p;

	(void)content_size;
	DG("check 0");
	p = content;
	DG("check 1");
	ft_strdel(&p->path);
	DG("check 2");
	ft_sstrfree(p->av);
	DG("check 3");
	free(p);
}
