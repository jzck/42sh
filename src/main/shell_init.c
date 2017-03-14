/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 21:50:11 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cliopts	shell_opts[] =
{
	{'c', NULL, SH_OPTS_LC, SH_OPTS_JOBC | SH_INTERACTIVE, NULL},
	{-1, "no-jobcontrol", 0, SH_OPTS_JOBC, NULL},
	{0, 0, 0, 0, 0},
};

static int			interactive_settings(void)
{
	int		*shell_pgid;
	t_data	*data;

	data = data_singleton();
	DG("interactive shell settings");
	shell_pgid = &data->jobc.shell_pgid;
	while (tcgetpgrp(STDIN) != (*shell_pgid = getpgrp()))
		kill(-*shell_pgid, SIGTTIN);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, sigtstp_handler);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, SIG_DFL);
	signal(SIGWINCH, sigwinch_resize);
	*shell_pgid = getpid();
	if (setpgid(*shell_pgid, *shell_pgid))
	{
		ft_dprintf(2, "Couldnt put the shell in it's own process group");
		exit (1);
	}
	tcsetpgrp(STDIN, *shell_pgid);
	tcgetattr(STDIN, &data->jobc.shell_tmodes);
	return (0);
}

int					shell_init(int ac, char **av)
{
	t_data	*data;

	data = data_singleton();
	data_init(ac, av);
	if (isatty(STDIN) && !*cliopts_getdata(av))
	{
		DG("interactive");
		data->opts |= SH_INTERACTIVE;
		data->opts |= SH_OPTS_JOBC;
	}
	else
		DG("non interactive");
	if (cliopts_get(av, shell_opts, data))
		return (ft_perror());
	if (SH_IS_INTERACTIVE(data->opts))
		interactive_settings();
	else
		DG("not interactive");
	return (0);
}
