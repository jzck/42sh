/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:22:34 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 16:49:05 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_prompt(void)
{
	t_data	*data;

	data = data_singleton();
	while (data->jobc.list)
	{
		/* usleep(500 * 1000); */
		if (check_chlds())
			continue ;
		else
			break ;
	}
	ft_putstr(SHELL_PROMPT);
	return (0);
}
