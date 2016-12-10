/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 17:58:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(t_data *data)
{
	char		*term_name;

	atexit(&ft_cleanup);
	data->line.input = NULL;
	data->env = ft_sstrdup(environ);
	data->line.history = NULL;
	data->exec.fdin = STDIN;
	data->exec.fdout = STDOUT;
	data->exec.aol_status = NULL;
	data->exec.aol_search = 0;
	data->exec.amp = 0;
	data->jobc.list = NULL;
	if (!(data->line.history = ft_dlstnew(NULL, 0)))
		return (-1);
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	if (signal(SIGINT, sigint_handler) == SIG_ERR)
		ft_dprintf(STDERR, "\ncan't catch SIGINT\n");
	if (signal(SIGTSTP, sigtstp_handler) == SIG_ERR)
		ft_dprintf(STDERR, "\ncan't catch SIGTSTP\n");
	if (signal(SIGCHLD, sigchld_handler) == SIG_ERR)
		ft_dprintf(STDERR, "\ncan't catch SIGCHLD\n");
	return (0);
}
