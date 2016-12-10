/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_sh.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 09:44:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 10:24:12 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

t_data				**data_singleton(void)
{
	static t_data	*data;

	return (&data);
}

int		ft_interactive_sh(t_data *data)
{
	*data_singleton() = data;
	return (ft_readline(&data->line));
}
