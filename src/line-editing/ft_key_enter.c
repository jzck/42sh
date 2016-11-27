/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:30 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/27 20:23:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_enter(t_data *data, char *buf)
{
	(void)buf;
	if (data->state_now == Q_NONE)
	{
		ft_putchar('\n');
		ft_history_add(data);
		return (2);
	}
	ft_key_default(data, buf);
	ft_printf("> ");
	return (0);
}
