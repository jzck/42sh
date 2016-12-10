/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:06 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:27:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_history_down(t_data *data, char *buf)
{
	int		i;
	char	*str;

	(void)buf;
	if (!data->line.history)
		return (0);
	if (!data->line.history->next)
		return (0);
	data->line.history = data->line.history->next;
	str = data->line.history->content;
	i = 0;
	if (!data->line.history->next)
		ft_strdel(&str);
	return (0);
}
