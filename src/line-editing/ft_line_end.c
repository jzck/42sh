/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:33 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_line_end(t_data *data, t_dlist **input_chain, char *buf)
{
	while (ft_cursor_right(data, input_chain, buf))
		;
	return (0);
}
