/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_read_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:00:03 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 21:15:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bt_read_getdelim(char ***av, t_read *data)
{
	if (!av || !*av)
		return (1);
	data->delim = ***av;
	return (0);
}

int		bt_read_getnchars(char ***av, t_read *data)
{
	if (!av || !*av)
		return (1);
	data->nchars = ft_atoi(**av);
	return (0);
}

int		bt_read_getprompt(char ***av, t_read *data)
{
	DG("getting prompt");
	if (!av || !*av || !**av)
		return (1);
	data->prompt = **av;
	DG("got prompt [%s]", data->prompt);
	return (0);
}

int		bt_read_gettimeout(char ***av, t_read *data)
{
	if (!av || !*av)
		return (1);
	data->timeout = ft_atoi(**av);
	return (0);
}

int		bt_read_getfd(char ***av, t_read *data)
{
	if (!av || !*av)
		return (1);
	data->fd = ft_atoi(**av);
	return (0);
}
