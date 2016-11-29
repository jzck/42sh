/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:57:43 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/29 15:57:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_del(t_data *data, char *buf)
{
	char	*res;

	(void)data;
	(void)buf;
	if (!data->input_pos)
		return (0);
	if (data->input[data->input_pos - 1] == '\n')
		return (0);
	qstate_update(data, -1);
	ft_strcpy(data->input + data->input_pos - 1,
				data->input + data->input_pos);
	data->input_pos--;
	if ((res = tgetstr("le", NULL)) == NULL)
	{
		ft_printf("le error\n");
		return (-1);
	}
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	if ((res = tgetstr("DC", NULL)) == NULL)
	{
		ft_printf("DC error\n");
		return (-1);
	}
	tputs(tgoto(res, 0, 0), 0, &ft_putchar);
	return (1);
}
