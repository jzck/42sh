/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:06 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:06 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_history_down(t_data *data, char *buf)
{
	int		i;
	char	*str;

	(void)buf;
	if (!data->history)
		return (0);
	if (!data->history->next)
		return (0);
	data->history = data->history->next;
	str = data->history->content;
	/* *input_chain = ft_dlstlast(*input_chain); */
	/* ft_clear_input(input_chain); */
	i = 0;
	/* while (str[i]) */
	/* 	ft_key_basic(data, input_chain, str + i++); */
	if (!data->history->next)
		ft_strdel(&str);
	return (0);
}
