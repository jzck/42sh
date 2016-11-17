/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_left.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_word_left(t_data *data, char *buf)
{
	ft_cursor_left(data, buf);
	while (FT_WS(data->input[data->input_pos - 1]))
	{
		if (!ft_cursor_left(data, buf))
			return (0) ;
	}
	while (!FT_WS(data->input[data->input_pos - 1]))
	{
		if (!ft_cursor_left(data, buf))
			return (0);
	}
	return (0);
}
