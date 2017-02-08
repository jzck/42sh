/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 17:07:38 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(int ac, char **av)
{
	int		*shell_pgid;
	t_data	*data;

	data_init();
	data = data_singleton();
	data->argc = ac;
	data->argv = ft_sstrdup(av);
	atexit(&shell_exit);
	shell_get_opts(ac, av);
	if (SH_IS_INTERACTIVE(data->opts))
	{
		DG("interactive shell settings");
		shell_pgid = &data->jobc.shell_pgid;
		while (tcgetpgrp(STDIN) != (*shell_pgid = getpgrp()))
			kill(-*shell_pgid, SIGTTIN);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, sigtstp_handler);
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
		signal(SIGCHLD, sigchld_handler);
		*shell_pgid = getpid();
		if (setpgid(*shell_pgid, *shell_pgid))
		{
			ft_dprintf(2, "Couldnt put the shell in it's own process group");
			exit (1);
		}
		tcsetpgrp(STDIN, *shell_pgid);
		tcgetattr(STDIN, &data->jobc.shell_tmodes);
	}
}
