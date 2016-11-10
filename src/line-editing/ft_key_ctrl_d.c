/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 13:44:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_ctrl_d(t_data *data, t_dlist **input_chain, char *buf)
{
	(void)data;
	(void)input_chain;
	(void)buf;
	ft_putendl("exit");
	exit(0);
}
