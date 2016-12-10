/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_select_left_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:06:59 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 13:28:20 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_select_wleft_function(t_line *line, long int input)
{
	int	ret;

	if (!line->pos)
		return (0);
	if (!RL_IS(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_wleft_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_post(line);
	return (ret);
}
