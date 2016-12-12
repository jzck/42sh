/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_select_right_function.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 03:16:57 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:37:31 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_readline.h"

int		rl_select_right_function(t_line *line, long int input)
{
	int	ret;

	if (line->pos == line->used)
		return (0);
	if (!RL_IS(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_right_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_ante(line);
	return (ret);
}
