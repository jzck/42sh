/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_read_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:00:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 18:11:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bt_read_getdelim(t_read *data, char *arg)
{
	data->delim = *arg;
	return (0);
}

int		bt_read_getnchars(t_read *data, char *arg)
{
	data->nchars = ft_atoi(arg);
	return (0);
}

int		bt_read_getprompt(t_read *data, char *arg)
{
	data->prompt = arg;
	return (0);
}

int		bt_read_gettimeout(t_read *data, char *arg)
{
	data->timeout = ft_atoi(arg);
	return (0);
}

int		bt_read_getfd(t_read *data, char *arg)
{
	data->fd = ft_atoi(arg);
	return (0);
}
