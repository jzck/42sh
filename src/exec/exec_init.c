/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 21:28:09 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 19:46:42 by jhalford         ###   ########.fr       */
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
	job_init(&exec->job);
	exec->attrs = 0;
	exec->fdin = STDIN;
	exec->op_stack = NULL;
	return (0);
}
