/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 15:11:34 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(void)
{
	int		*shell_pgid;

	shell_pgid = &data_singleton()->jobc.shell_pgid;
	data_init();
	atexit(&shell_exit);
	if (isatty(STDIN))
	{
		while (tcgetpgrp(STDIN) != (*shell_pgid = getpgrp()))
			kill(-*shell_pgid, SIGTTIN);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
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
}
