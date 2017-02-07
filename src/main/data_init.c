/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/07 17:23:02 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(void)
{
	char	*term_name;
	t_data	*data;

	data = data_singleton();
	data->env = ft_sstrdup(environ);
	data->comp = NULL;
	data->opts = SHELL_OPTS_JOBC;

	data->exec.process.path = NULL;
	data->exec.process.av = NULL;
	data->exec.process.fdin = STDIN;
	data->exec.process.fdout = STDOUT;
	data->exec.process.pid = 0;
	data->exec.process.attributes = PROCESS_PIPESTART | PROCESS_PIPEEND;
	data->exec.process.redirs = NULL;
	data->exec.fd0save = dup(0);
	data->exec.fd1save = dup(1);
	data->exec.fd2save = dup(2);

	data->exec.aol_status = NULL;
	data->exec.aol_search = 0;
	data->exec.job.id = 0;
	data->exec.job.pgid = 0;
	data->exec.job.attributes = 0;
	data->exec.job.first_process = 0;
	data->jobc.first_job = NULL;
	data->jobc.current_id = 1;
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	return (0);
}
