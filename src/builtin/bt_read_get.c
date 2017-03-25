/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_read_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:00:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 01:27:06 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bt_read_getdelim(char *opt_arg, t_read *data)
{
	if (!opt_arg)
		return (1);
	if (data)
		data->delim = *opt_arg;
	return (0);
}

int		bt_read_getnchars(char *opt_arg, t_read *data)
{
	if (!opt_arg)
		return (1);
	if (data)
		data->nchars = ft_atoi(opt_arg);
	return (0);
}

int		bt_read_getprompt(char *opt_arg, t_read *data)
{
	if (!opt_arg)
		return (1);
	if (data)
		data->prompt = opt_arg;
	return (0);
}

int		bt_read_gettimeout(char *opt_arg, t_read *data)
{
	if (!opt_arg)
		return (1);
	if (data)
		data->timeout = ft_atoi(opt_arg);
	return (0);
}

int		bt_read_getfd(char *opt_arg, t_read *data)
{
	if (!opt_arg)
		return (1);
	if (data)
		data->fd = ft_atoi(opt_arg);
	return (0);
}
