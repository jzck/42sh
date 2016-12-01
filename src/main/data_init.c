/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/01 17:31:00 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(t_data *data)
{
	atexit(&ft_cleanup);
	data->env = ft_sstrdup(environ);
	data->history = NULL;
	data->fdin = STDIN;
	data->fdout = STDOUT;
	data->aol_status = NULL;
	data->aol_search = 0;
	if (!(data->history = ft_dlstnew(NULL, 0)))
		return (-1);
	return (0);
}
