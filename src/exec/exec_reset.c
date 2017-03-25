/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 14:31:42 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 23:29:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_reset_job(t_job *job)
{
	job->id = 0;
	job->pgid = 0;
	job->attrs = 0;
	job->first_process = NULL;
	tcgetattr(STDIN, &job->tmodes);
	return (0);
}

int			exec_pushfds(void)
{
	int		i;
	t_exec	*exec;

	exec = &data_singleton()->exec;
	i = -1;
	while (++i < 10)
		push(&(exec->fd_save[i]), fcntl(i, F_DUPFD_CLOEXEC, 10));
	return (0);
}

int			exec_popfds(void)
{
	int		i;
	t_exec	*exec;

	exec = &data_singleton()->exec;
	i = -1;
	while (++i < 10)
		pop(&exec->fd_save[i]);
	return (0);
}

int			exec_reset(void)
{
	t_jobc	*jobc;
	t_exec	*exec;

	exec = &data_singleton()->exec;
	jobc = &data_singleton()->jobc;
	exec_pushfds();
	exec->op_stack = NULL;
	exec->fdin = STDIN;
	exec->attrs = 0;
	exec_reset_job(&exec->job);
	jobc->first_job = NULL;
	jobc->current_id = 1;
	return (0);
}

int			exec_destroy(void)
{
	int		i;
	t_jobc	*jobc;
	t_exec	*exec;

	exec = &data_singleton()->exec;
	jobc = &data_singleton()->jobc;
	ft_lstdel(&exec->op_stack, ft_lst_cfree);
	ft_lstdel(&jobc->first_job, job_free);
	i = -1;
	while (++i < 10)
		ft_lstdel(&exec->fd_save[i], ft_lst_cfree);
	return (0);
}
