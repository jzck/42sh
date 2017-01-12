/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_default_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:30:38 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 11:50:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_default_function(t_line *line, long int input)
{
	if (!ft_isprint(input))
		return (0);
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (RL_IS(line->bitset, RL_INSERT))
	{
		if (input_move(line, (char *)&input, sizeof(char)) < 0)
			return (-1);
	}
	else
	{
		if (input_maj(line, (char *)&input, sizeof(char)) < 0)
			return (-1);
	}
	rl_reset_display_post(line);
	curs_forward(&line->curs, sizeof(char));
	line->pos += 1;
/*	curs_write(&line->curs, (char *)&input, sizeof(char));
	line->pos += 1;
	rl_reset_display_post(line);
*/	return (0);
}
