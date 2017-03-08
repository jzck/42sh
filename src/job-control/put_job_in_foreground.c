/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_job_in_foreground.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:58:36 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 17:47:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		put_job_in_foreground(t_job *j, int cont)
{
	t_jobc	*jobc;

	jobc = &data_singleton()->jobc;
	if (SH_HAS_JOBC(data_singleton()->opts))
	{
		tcsetpgrp(STDIN, j->pgid);
		if (cont)
		{
			tcsetattr(STDIN, TCSADRAIN, &j->tmodes);
			if (kill(-j->pgid, SIGCONT) < 0)
				DG("kill(SIGCONT) failed");
		}
		job_wait(j->id);
		job_remove(j->id);
		tcsetpgrp(STDIN, jobc->shell_pgid);
		tcgetattr(STDIN, &j->tmodes);
		tcsetattr(STDIN, TCSADRAIN, &jobc->shell_tmodes);
	}
	else
	{
		job_wait(j->id);
		job_remove(j->id);
	}
	return (0);
}
