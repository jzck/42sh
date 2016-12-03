/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:32:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(t_data *data)
{
	atexit(&ft_cleanup);
	data->env = ft_sstrdup(environ);
	data->line.history = NULL;
	data->exec.fdin = STDIN;
	data->exec.fdout = STDOUT;
	data->exec.aol_status = NULL;
	data->exec.aol_search = 0;
	if (!(data->line.history = ft_dlstnew(NULL, 0)))
		return (-1);
	return (0);
}
