/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:28:41 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/18 16:48:42 by gwojda           ###   ########.fr       */
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
	if (jlist && !notified)
	{
		notified = 1;
		ft_dprintf(2, "{red}%s: you have live jobs (running or suspended).{eoc}\n", SHELL_NAME);
		return (0);
	}
	if (av[1])
		status = ft_atoi(av[1]);
	else
	{
		/* status = ft_atoi(ft_getenv(data_singleton()->env, "?")); */
		status = 0;
	}
	ft_save_termios(-1);
	ft_free_hash_table();
	exit(status);
	return (0);
}
