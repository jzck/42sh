/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:26:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 19:46:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		data_init(t_data *data)
{
	data->env = ft_sstrdup(environ);
	data->history = NULL;
	data->fdin = STDIN;
	data->fdout = STDOUT;
	data->save_in = dup(STDIN);
	data->save_out = dup(STDOUT);
	if (!(data->history = ft_dlstnew(NULL, 0)))
		return (-1);
	return (0);
}
