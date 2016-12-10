/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:43:31 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:26:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_cursor_right(t_data *data, char *buf)
{
	char	*res;

	res = NULL;
	(void)buf;
	if (!data->line.input[data->line.input_pos])
		return (0);
	if (data->line.input[data->line.input_pos] == '\n')
		return (0);
	data->line.input_pos++;
	if ((res = tgetstr("nd", NULL)) == NULL)
		return (-1);
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (1);
}
