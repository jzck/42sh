/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:58:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		put_job_in_foreground(t_job *job, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	/* Put the job into the foreground.  */
	tcsetpgrp(STDIN_FILENO, job->pgid);
	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		tcsetattr (STDIN_FILENO, TCSADRAIN, &job->tmodes);
		if (kill(-job->pgid, SIGCONT) < 0)
			perror("kill (SIGCONT)");
	}
	/* Wait for it to report.  */
	job_wait(job);
	job_remove(job->id);

	/* Put the shell back in the foreground.  */
	tcsetpgrp(STDIN_FILENO, jobc->shell_pgid);

	/* Restore the shell’s terminal modes.  */
	tcgetattr(STDIN_FILENO, &job->tmodes);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &jobc->shell_tmodes);
	return (0);
}
