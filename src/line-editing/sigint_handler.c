/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigint_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 15:14:47 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 15:31:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int signo)
{
	t_job	*job;

	(void)signo;
	job = &data_singleton()->exec.job;
	DG("got SIGINT; job->pgid=%i", job->pgid);
	if (job->pgid)
		kill(job->pgid, SIGINT);
	if (kill(job->pgid, 0) == 0)
		ft_putchar('\n');
}
