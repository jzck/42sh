/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/12 13:16:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		put_job_in_foreground(t_job *job, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	/* Send the job a continue signal, if necessary. */
	if (cont)
	{
		/* Put the job into the foreground. */
		signal(SIGTTOU, SIG_IGN);
		if (tcsetpgrp(STDIN, job->pgid) == -1)
			DG("couldn't put process in control. errno=%i, pgid=%i", errno, job->pgid);
		signal(SIGTTOU, sigttou_handler);
		tcsetattr (STDIN, TCSANOW, &job->tmodes);
		if (kill(-job->pgid, SIGCONT) < 0)
			perror("kill (SIGCONT)");
	}
	/* Wait for it to report.  */
	DG("gonna wait for job id=%i", job->id);
	job_wait(job->id);
	job_remove(job->id);

	/* Put the shell back in the foreground. */
	signal(SIGTTOU, SIG_IGN);
	tcsetpgrp(STDIN, jobc->shell_pgid);
	signal(SIGTTOU, sigttou_handler);

	/* Restore the shell’s terminal modes. */
	tcgetattr(STDIN, &job->tmodes);
	tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	return (0);
}
