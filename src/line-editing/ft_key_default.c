/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:45:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 17:18:25 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int	ft_key_default(t_data *data, char *buf)
{
	char	*res;
	char	*tmp;

	tmp = data->line.input;
	data->line.input = ft_strinsert(data->line.input, *buf, data->line.input_pos);
	data->line.input_pos++;
	ft_strdel(&tmp);
	qstate_update(data, *buf);
	if ((res = tgetstr("IC", NULL)))
	{
		tputs(tgoto(res, 0, 0), 1, &ft_putchar);
		ft_putchar(buf[0]);
		return (0);
	}
	else
		return (-1);
}
