/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int	ft_key_default(t_data *data, char *buf)
{
	char	*res;
	char	*tmp;

	tmp = data->input;
	data->input = ft_strinsert(data->input, *buf, data->input_pos);
	data->input_pos++;
	ft_strdel(&tmp);
	quote_update(data, *buf);
	if ((res = tgetstr("IC", NULL)))
	{
		tputs(tgoto(res, 0, 0), 1, &ft_putchar);
		ft_putchar(buf[0]);
		return (0);
	}
	else
		return (-1);
}
