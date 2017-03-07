/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 15:48:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 16:39:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		launch_builtin(t_process *p)
{
	pid_t	pid;

	if (IS_PIPESINGLE(*p))
	{
		if (process_redirect(p))
			return (1);
		set_exitstatus((*p->execf)(p->path, p->av, data_singleton()->env), 1);
		return (1);
	}
	pid = fork();
	if (pid == 0)
	{
		process_setgroup(p, 0);
		process_setsig();
		if (process_redirect(p))
			exit (1);
		exit((*p->execf)(p->path, p->av, data_singleton()->env));
	}
	else if (pid > 0)
		return (0);
	else if (pid == -1)
		ft_dprintf(2, "{red}%s: internal fork error{eoc}\n", SHELL_NAME);
	return (1);
}
