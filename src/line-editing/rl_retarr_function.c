/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_retarr_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 20:06:50 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:04:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_retarr_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (!line->pos)
		return (0);
	input_remove(line, 1);
	curs_backward(&line->curs, 1);
	line->pos -= 1;	
	rl_reset_display_post(line);
	return (0);
	(void)input;
}
