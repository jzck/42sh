/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:43:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 16:52:48 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_history_add(t_data *data)
{
	t_dlist	*new;
	char	*str;

	str = data->line.input;
	if (data->line.history)
		while (data->line.history->next)
			data->line.history = data->line.history->next;
	if (!data->line.history->prev
			|| ft_strcmp(str, (char *)data->line.history->prev->content))
	{
		new = ft_dlstnew(str, sizeof(char) * (ft_strlen(str) + 1));
		ft_dlstadd_before(&data->line.history, new);
		data->line.history = data->line.history->next;
		ft_strdel((char **)&data->line.history->content);
	}
	return (0);
}
