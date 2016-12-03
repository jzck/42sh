/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:15 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:28:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_history_up(t_data *data, char *buf)
{
	int		i;
	char	*str;

	(void)buf;
	if (!data->line.history)
		return (0);
	if (!data->line.history->prev)
		return (0);
	data->line.history = data->line.history->prev;
	str = data->line.history->content;
	i = 0;
	return (0);
}
