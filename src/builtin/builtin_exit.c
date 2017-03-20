/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:41 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 14:17:40 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_exit(const char *path, char *const av[], char *const envp[])
{
	int			status;
	static int	notified = 0;
	t_jobc		*jobc;
	t_list		*jlist;

	(void)envp;
	(void)path;
	jobc = &data_singleton()->jobc;
	jlist = jobc->first_job;
	if (SH_HAS_JOBC(data_singleton()->opts) && jlist && !notified)
	{
		notified = 1;
		ft_dprintf(2, "%s: you have live jobs (running or suspended)\n",
				data_singleton()->argv[0]);
		return (0);
	}
	status = (av && av[1]) ?
			ft_atoi(av[1]) : ft_atoi(ft_getenv(data_singleton()->env, "?"));
	if (SH_IS_INTERACTIVE(data_singleton()->opts))
		tcsetattr(STDIN, TCSANOW, &data_singleton()->jobc.shell_tmodes);
	job_hup_all();
	data_exit();
	exit(status);
	return (0);
}
