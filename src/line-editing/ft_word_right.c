/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:37 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_word_right(t_data *data, char *buf)
{
	while (!FT_WS(data->input[data->input_pos]))
	{
		if (!ft_cursor_right(data, buf))
			return (0);
	}
	while (FT_WS(data->input[data->input_pos]))
	{
		if (!ft_cursor_right(data, buf))
			return (0) ;
	}
	return (0);
}
