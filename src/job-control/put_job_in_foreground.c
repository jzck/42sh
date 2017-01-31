/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 15:10:45 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		put_job_in_foreground(t_job *job, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	if (cont)
	{
		signal(SIGTTOU, SIG_IGN);
		if (tcsetpgrp(STDIN, job->pgid) == -1)
			return (1);
		signal(SIGTTOU, sigttou_handler);
		tcsetattr(STDIN, TCSANOW, &job->tmodes);
		if (kill(-job->pgid, SIGCONT) < 0)
			perror("kill (SIGCONT)");
	}
	job_wait(job->id);
	job_remove(job->id);
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(STDIN, jobc->shell_pgid);
	signal(SIGTTOU, sigttou_handler);
	tcgetattr(STDIN, &job->tmodes);
	tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	return (0);
}
