/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:56:36 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:30:46 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_enter(t_data *data, char *buf)
{
	(void)buf;
	if (*(t_qstate*)data->line.qstack->content == Q_NONE)
	{
		ft_putchar('\n');
		ft_history_add(data);
		return (2);
	}
	ft_key_default(data, buf);
	ft_printf("> ");
	return (0);
}
