/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/13 15:06:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control.h"

int		put_job_in_foreground(t_job *job, int cont)
{
	t_jobc	*jobc;

	/* Put the job into the foreground.  */
	tcsetpgrp(shell_terminal, job->pgid);
	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		tcsetattr (shell_terminal, TCSADRAIN, &job->tmodes);
		if (kill(- job->pgid, SIGCONT) < 0)
			perror("kill (SIGCONT)");
	}
	/* Wait for it to report.  */
	wait_for_job(j);

	/* Put the shell back in the foreground.  */
	tcsetpgrp(shell_terminal, jobc->shell_pgid);

	/* Restore the shell’s terminal modes.  */
	tcgetattr(shell_terminal, &job->tmodes);
	tcsetattr(shell_terminal, TCSADRAIN, &jobc->shell_tmodes);
}
