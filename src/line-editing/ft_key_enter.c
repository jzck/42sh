/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_enter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:30 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 14:21:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_enter(t_data *data, t_dlist **input_chain, char *buf)
{
	if (ft_input_is_escaped(*input_chain))
	{
		ft_key_basic(data, input_chain, buf);
		ft_printf("> ");
		return (0);
	}
	ft_putchar('\n');
	ft_history_add(data, *input_chain);
	ft_dlstdel(input_chain, ft_lst_cfree);
	return (2);
}
