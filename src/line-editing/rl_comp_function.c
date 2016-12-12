/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_comp_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:49:03 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 11:01:45 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		ft_autocomp(t_data *data)
{
	return (0);
	int			li;
	int			co;

	li = data->line.curs.li;
	co = data->line.curs.co;
	ft_putstr("\nTeeeeeeest");
	data->line.input = ft_strjoin(data->line.input, " JOIN ");
	curs_goto(&data->line.curs, li, co + 6);
	return (0);
}

int			rl_comp_function(t_line *line, long int input)
{
	t_data	*data;

	data = *data_singleton();
	if (ft_autocomp(data) < 0)
		return (-1);
	line->size = ft_strlen(line->input);
	line->used = line->size;
	curs_reset(0);
	return (0);
}
