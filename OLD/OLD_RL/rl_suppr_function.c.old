/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_suppr_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 02:23:56 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:04:43 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_suppr_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (line->pos == line->used)
		return (0);
	input_remove(line, -1);
	rl_reset_display_post(line);
	return (0);
	(void)input;
}
