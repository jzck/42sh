/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/13 17:37:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		put_job_in_foreground(t_job *j, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	DG("tcsetpgrp[%i]", j->pgid);
	if (SH_IS_INTERACTIVE(data_singleton()->opts))
		tcsetpgrp(STDIN, j->pgid);
	if (cont)
	{
		tcsetattr(STDIN, TCSADRAIN, &j->tmodes);
		if (kill(-j->pgid, SIGCONT) < 0)
			DG("kill(SIGCONT) failed");
	}
	DG("check");
	job_wait(j->id);
	DG("check");
	job_remove(j->id);
	DG("check");
	if (SH_IS_INTERACTIVE(data_singleton()->opts))
	{
		tcsetpgrp(STDIN, jobc->shell_pgid);
		tcgetattr(STDIN, &j->tmodes);
		tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	}
	return (0);
}
