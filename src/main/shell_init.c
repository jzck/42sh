/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 11:09:31 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_init(int ac, char **av)
{
	int		*shell_pgid;
	t_data	*data;

	DG("check");
	data_init();
	data = data_singleton();
	data->argc = ac;
	data->argv = ft_sstrdup(av);
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
	}
}
