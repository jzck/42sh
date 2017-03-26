/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:28:09 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 22:13:04 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			job_init(t_job *job)
{
	job->id = 0;
	job->pgid = 0;
	job->attrs = 0;
	job->first_process = NULL;
	tcgetattr(STDIN, &job->tmodes);
	return (0);
}

int			exec_init(t_exec *exec)
{
	t_jobc	*jobc;
	int		i;

	jobc = &data_singleton()->jobc;
	job_init(&exec->job);
	i = -1;
	while (++i < 10)
		exec->fd_save[i] = NULL;
	exec_pushfds();
	exec->attrs = 0;
	exec->fdin = STDIN;
	exec->op_stack = NULL;
	jobc->first_job = NULL;
	jobc->current_id = 1;
	return (0);
}
