/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:41 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 13:50:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define EXITERR_0 SHELL_NAME ": numeric argument required\n"

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
	if (av && av[1] && !ft_stris(av[1], ft_isdigit))
		error_msg(EXITERR_0);
	status = (av && av[1]) ?
			ft_atoi(av[1]) : ft_atoi(ft_getenv(data_singleton()->env, "?"));
	if (SH_IS_INTERACTIVE(data_singleton()->opts))
		tcsetattr(STDIN, TCSANOW, &data_singleton()->jobc.shell_tmodes);
	job_hup_all();
	data_exit();
	exit(status);
	return (0);
}
