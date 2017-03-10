/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 15:16:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		put_job_in_foreground(t_job *j, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	DG("givving terminal to job [%i]", j->pgid);
	tcsetpgrp(STDIN, j->pgid);
	/* tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes); */

	if (cont)
	{
		tcsetattr(STDIN, TCSADRAIN, &j->tmodes);
		if (kill(-j->pgid, SIGCONT) < 0)
			DG("kill(SIGCONT) failed");
	}
	job_wait(j->id);
	job_remove(j->id);

	tcsetpgrp(STDIN, jobc->shell_pgid);
	/* if (SH_HAS_JOBC(data_singleton()->opts)) */
	/* { */
		tcgetattr(STDIN, &j->tmodes);
		tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	/* } */
	return (0);
}
