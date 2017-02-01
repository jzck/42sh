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

int		put_job_in_foreground(t_job *j, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	DG("pid:%i gonna setpgrp(%i) (JOB)", getpid(), j->pgid);
	tcsetpgrp(STDIN, j->pgid);
	tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);

	if (cont)
	{
		tcsetattr(STDIN, TCSADRAIN, &j->tmodes);
		if (kill(-j->pgid, SIGCONT) < 0)
			DG("kill(SIGCONT) failed");
	}
	job_wait(j->id);
	DG("finished waiting for [%i]", j->id);
	job_remove(j->id);

	DG("pid:%i gonna setpgrp(%i) (SHELL)", getpid(), jobc->shell_pgid);
	tcsetpgrp(STDIN, jobc->shell_pgid);

	tcgetattr(STDIN, &j->tmodes);
	tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	return (0);
}
