/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/07 16:38:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(void)
{
	t_data	*data;
	char	*term_name;

	data = data_singleton();
	data->env = ft_sstrdup(environ);
	data->comp = NULL;
	data->opts = 0;
	data->exec.fd_save[0] = fcntl(0, F_DUPFD_CLOEXEC);
	data->exec.fd_save[1] = fcntl(1, F_DUPFD_CLOEXEC);
	data->exec.fd_save[2] = fcntl(2, F_DUPFD_CLOEXEC);
	data->exec.op_stack = NULL;
	data->exec.fdin = STDIN;
	data->exec.attrs = 0;

	data->exec.job.id = 0;
	data->exec.job.pgid = 0;
	data->exec.job.attrs = 0;
	data->exec.job.first_process = NULL;

	data->jobc.first_job = NULL;
	data->jobc.current_id = 1;

	data->local_var = NULL;
	data->lst_func = NULL;
	if ((term_name = ft_getenv(data->env, "TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, term_name) != 1)
		return (-1);
	return (0);
}
