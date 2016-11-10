/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:42:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:42:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_clear_line(t_data *data, t_dlist **input_chain, char *buf)
{
	ft_line_end(data, input_chain, buf);
	while (ft_key_del(data, input_chain, buf))
		;
	return (1);
}
