/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/31 20:02:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(int ac, char **av)
{
	int		*shell_pgid;

	data_init();
	data_singleton()->argc = ac;
	data_singleton()->argv = ft_sstrdup(av);
	atexit(&shell_exit);
	if (isatty(STDIN))
	{
		shell_pgid = &data_singleton()->jobc.shell_pgid;
		while (tcgetpgrp(STDIN) != (*shell_pgid = getpgrp()))
			kill(-*shell_pgid, SIGTTIN);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, sigtstp_handler);
		/* signal(SIGTSTP, SIG_IGN); */
		signal(SIGTTIN, sigttin_handler);
		signal(SIGTTOU, sigttou_handler);
		signal(SIGCHLD, sigchld_handler);
		*shell_pgid = getpid();
		if (setpgid(*shell_pgid, *shell_pgid))
		{
			ft_dprintf(2, "Couldnt put the shell in it's own process group");
			exit (1);
		}
		tcsetpgrp(STDIN, *shell_pgid);
		tcgetattr(STDIN, &data_singleton()->jobc.shell_tmodes);
	}
	read_script(av[1]);
	shell_get_opts(ac, av);
}
