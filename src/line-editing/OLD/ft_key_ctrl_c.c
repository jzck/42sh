/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_ctrl_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/03 15:29:09 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_ctrl_c(t_data *data, char *buf)
{
	(void)buf;
	ft_strdel(&data->line.input);
	data->line.input = ft_memalloc(10);
	ft_putendl("");
	ft_prompt();
	return (0);
}
